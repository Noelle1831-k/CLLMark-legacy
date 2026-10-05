def predict_anomalies(model, data):
    # Predict anomalies using the trained model
    predictions = model.predict(data)
    # Extract anomalies from the data
    anomalies = data[predictions == -1]
    return anomalies