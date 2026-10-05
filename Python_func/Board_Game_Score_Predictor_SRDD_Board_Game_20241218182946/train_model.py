def train_model(self, features, labels):
        '''
        Train the machine learning model using the provided features and labels.
        '''
        X_train, X_test, y_train, y_test = train_test_split(features, labels, test_size=0.2, random_state=42)
        # Initialize the model
        model = RandomForestRegressor(n_estimators=100, random_state=42)
        # Train the model
        model.fit(X_train, y_train)
        # Optionally, evaluate the model on the test set and print the score
        test_score = model.score(X_test, y_test)
        print(f"Model Test R^2 Score: {test_score:.2f}")
        return model