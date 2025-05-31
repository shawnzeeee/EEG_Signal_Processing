import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import classification_report, confusion_matrix
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
from sklearn.manifold import TSNE


# Load the processed CSV file
data = pd.read_csv("processed_features.csv")

# Separate features and labels
X = data.iloc[:, :-1].values  # All columns except the last one (features)
y = data.iloc[:, -1].values   # The last column (class labels)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train an SVM classifier
svm = SVC(kernel='linear', random_state=42)
svm.fit(X_train, y_train)

# Make predictions
y_pred = svm.predict(X_test)

# Print classification report
print("Classification Report:")
print(classification_report(y_test, y_pred))

# Plot confusion matrix
conf_matrix = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(6, 6))
plt.imshow(conf_matrix, cmap='Blues', interpolation='nearest')
plt.title("Confusion Matrix")
plt.colorbar()
plt.xticks([0, 1], ["Idle", "Active"])
plt.yticks([0, 1], ["Idle", "Active"])
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.text(0, 0, conf_matrix[0, 0], ha='center', va='center', color='white')
plt.text(0, 1, conf_matrix[0, 1], ha='center', va='center', color='black')
plt.text(1, 0, conf_matrix[1, 0], ha='center', va='center', color='black')
plt.text(1, 1, conf_matrix[1, 1], ha='center', va='center', color='white')
plt.show()

tsne = TSNE(n_components=2, random_state=42, perplexity=30, n_iter=1000)
X_tsne = tsne.fit_transform(X)

# Plot t-SNE visualization
plt.figure(figsize=(8, 6))
plt.scatter(X_tsne[:, 0], X_tsne[:, 1], c=y, cmap='coolwarm', edgecolors='k', s=20)
plt.title("t-SNE Visualization of Data")
plt.xlabel("t-SNE Component 1")
plt.ylabel("t-SNE Component 2")
plt.colorbar(label="Class")
plt.show()