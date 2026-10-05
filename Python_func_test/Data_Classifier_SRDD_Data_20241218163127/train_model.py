def train_model(self, data, target):
        '''
        Trains the model on the provided data and target variable.
        '''
        try:
            model = RandomForestClassifier(n_estimators=100, random_state=42)
            model.fit(data, target)
            return model
        except Exception as e:
            print(f"Error training model: {e}")
            return None