
import torch
import torch.nn as nn
import torch.nn.functional as F

class CNNBiLSTMClassifier(nn.Module):
    def __init__(self, num_classes=11):
        super(CNNBiLSTMClassifier, self).__init__()

        self.cnn = nn.Sequential(
            nn.Conv1d(4, 32, kernel_size=5, padding=2),
            nn.BatchNorm1d(32),
            nn.ReLU(),
            nn.MaxPool1d(2),
            nn.Conv1d(32, 64, kernel_size=5, padding=2),
            nn.BatchNorm1d(64),
            nn.ReLU(),
            nn.MaxPool1d(2)
        )

        self.lstm = nn.LSTM(input_size=64, hidden_size=32, batch_first=True, bidirectional=True)
        
        self.bn = nn.BatchNorm1d(32 * 2)  # Match hidden size
        
        self.classifier = nn.Sequential(
            nn.Linear(32 * 2, 32),
            nn.ReLU(),
            nn.Dropout(0.3),
            nn.Linear(32, num_classes)
        )

    def forward(self, x):
        x = self.cnn(x)  # → (B, 64, T)
        x = x.permute(0, 2, 1)  # (B, T, 64)

        _, (hn, _) = self.lstm(x)  # hn: (2, B, 32) if bidirectional=True
        hn = torch.cat((hn[0], hn[1]), dim=1)  # (B, 64)

        hn = self.bn(hn)  # BatchNorm on full concatenated hidden state
        return self.classifier(hn)