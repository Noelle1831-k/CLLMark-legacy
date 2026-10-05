def detect_anomalies(self, data, variables, method='IsolationForest'):
        '''
        Detects anomalies in the dataset using the specified method.
        Parameters:
        - data: DataFrame containing the dataset to be analyzed.
        - variables: List of variables to analyze for anomalies.
        - method: The anomaly detection method to use ('IsolationForest', 'EllipticEnvelope', 'OneClassSVM').
        Returns:
        - anomalies: DataFrame containing the detected anomalies.
        '''
        if data is None or data.empty:
            print("No data available. Please import data first.")
            return pd.DataFrame()
        if method not in self.models:
            print(f"Invalid method '{method}'. Using default 'IsolationForest'.")
            method = 'IsolationForest'
        try:
            subset = data[variables].dropna()
            model = self.models[method]
            print(f"Fitting model: {method} on variables: {variables}")
            model.fit(subset)
            predictions = model.predict(subset)
            anomalies = subset[predictions == -1]
            print(f"Anomalies detected using {method}: {len(anomalies)}")
            return anomalies
        except Exception as e:
            print(f"Error detecting anomalies: {e}")
            return pd.DataFrame()