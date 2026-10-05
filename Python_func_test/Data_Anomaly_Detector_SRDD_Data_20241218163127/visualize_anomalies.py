def visualize_anomalies(self, anomalies, data):
        try:
            plt.figure(figsize=(10, 6))
            plt.scatter(data.index, data, c='blue', label='Normal')
            anomaly_indices = anomalies[0]  # Extract the indices from the tuple
            plt.scatter(data.index[anomaly_indices], data.iloc[anomaly_indices], c='red', label='Anomaly')
            plt.legend()
            plt.title('Anomaly Detection')
            plt.xlabel('Index')
            plt.ylabel('Value')
            plt.grid(True)
            plt.show()
            print("Anomalies visualized successfully.")
        except Exception as e:
            print(f"Error visualizing anomalies: {e}")