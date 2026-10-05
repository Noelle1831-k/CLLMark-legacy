def run_anomaly_detection(data):
    model = anomaly_detector.train_model(data)
    anomalies = anomaly_detector.predict_anomalies(model, data)
    return anomalies