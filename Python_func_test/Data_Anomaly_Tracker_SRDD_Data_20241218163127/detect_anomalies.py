def detect_anomalies(data):
    try:
        if data.empty:
            print("No data available for anomaly detection.")
            return None
        model = IsolationForest(contamination=0.1, random_state=42)
        data_values = data.select_dtypes(include=[np.number]).values
        if data_values.size == 0:
            print("No numeric data available for anomaly detection.")
            return None
        model.fit(data_values)
        predictions = model.predict(data_values)
        anomalies = data[predictions == -1]
        print(f"Anomalies detected: {len(anomalies)}")
        return anomalies
    except Exception as e:
        print(f"Error detecting anomalies: {e}")
        return None