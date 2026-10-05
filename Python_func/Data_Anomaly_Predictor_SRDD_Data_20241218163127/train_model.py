def train_model(data):
    # Initialize the IsolationForest model with a specific contamination rate
    model = IsolationForest(contamination=0.1, n_estimators=100, max_samples='auto', random_state=42, n_jobs=-1)
    # Fit the model to the data
    model.fit(data)
    return model