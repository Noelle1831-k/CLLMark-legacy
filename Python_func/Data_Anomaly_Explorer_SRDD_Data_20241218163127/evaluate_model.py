def evaluate_model(self, data, variables, method='IsolationForest'):
        '''
        Evaluates the performance of the anomaly detection model using cross-validation.
        Parameters:
        - data: DataFrame containing the dataset to be analyzed.
        - variables: List of variables to analyze for anomalies.
        - method: The anomaly detection method to use ('IsolationForest', 'EllipticEnvelope', 'OneClassSVM').
        Returns:
        - score: The evaluation score of the model.
        '''
        from sklearn.model_selection import cross_val_score
        if data is None or data.empty:
            print("No data available. Please import data first.")
            return None
        if method not in self.models:
            print(f"Invalid method '{method}'. Using default 'IsolationForest'.")
            method = 'IsolationForest'
        try:
            subset = data[variables].dropna()
            model = self.models[method]
            print(f"Evaluating model: {method} on variables: {variables}")
            score = cross_val_score(model, subset, cv=5, scoring='accuracy')
            print(f"Model evaluation score using {method}: {score.mean()}")
            return score.mean()
        except Exception as e:
            print(f"Error evaluating model: {e}")
            return None