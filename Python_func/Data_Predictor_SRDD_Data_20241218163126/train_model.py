def train_model(self, data, target_variable):
        '''
        Trains a RandomForest model on the provided data.
        Splits data into training and testing sets.
        Evaluates model performance on the test set.
        '''
        X = data.drop(columns=[target_variable])
        y = data[target_variable]
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
        model = RandomForestClassifier(n_estimators=100, random_state=42)
        model.fit(X_train, y_train)
        # Evaluate model
        y_pred = model.predict(X_test)
        accuracy = accuracy_score(y_test, y_pred)
        report = classification_report(y_test, y_pred)
        print(f"Model Accuracy: {accuracy:.2f}")
        print("Classification Report:")
        print(report)
        return model