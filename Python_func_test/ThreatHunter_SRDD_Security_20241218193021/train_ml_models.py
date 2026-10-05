def train_ml_models(self, data, labels):
        print("Training ML models...")
        X_train, X_test, y_train, y_test = train_test_split(data, labels, test_size=0.2)
        self.model.fit(X_train, y_train)
        predictions = self.model.predict(X_test)
        print(f"Model accuracy: {accuracy_score(y_test, predictions)}")