def generate_visuals(data, anomalies):
    try:
        if data.empty:
            print("No data available for visualization.")
            return
        plt.figure(figsize=(12, 8))
        plt.scatter(data.index, data.values, label='Data', alpha=0.5)
        if anomalies is not None and not anomalies.empty:
            plt.scatter(anomalies.index, anomalies.values, color='red', label='Anomalies', alpha=0.7)
        plt.title('Data Anomalies')
        plt.xlabel('Index')
        plt.ylabel('Values')
        plt.legend()
        plt.grid(True)
        plt.show()
    except Exception as e:
        print(f"Error generating visuals: {e}")