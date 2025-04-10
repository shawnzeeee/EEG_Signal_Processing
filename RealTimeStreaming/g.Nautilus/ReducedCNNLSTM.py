import torch
import torch.nn as nn
import torch.nn.functional as F

class ReducedCNNLSTMClassifier(nn.Module):
    def __init__(self, num_classes=5):
        super(ReducedCNNLSTMClassifier, self).__init__()

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

        self.lstm = nn.LSTM(input_size=64, hidden_size=32, batch_first=True)
        
        self.bn = nn.BatchNorm1d(32)  # Match hidden size
        
        self.classifier = nn.Sequential(
            nn.Linear(32, 32),
            nn.ReLU(),
            nn.Dropout(0.3),
            nn.Linear(32, num_classes)
        )

    def forward(self, x):
        # x shape: (batch_size, channels, time) → (B, 4, 500)
        x = self.cnn(x)  # → (B, 64, time/4)
        x = x.permute(0, 2, 1)  # → (B, time/4, 64) for LSTM
        _, (hn, _) = self.lstm(x)        # hn: (1, B, 32)
        hn = hn.squeeze(0)               # → (B, 32)
        hn = self.bn(hn)                 # BatchNorm on final state
        return self.classifier(hn)