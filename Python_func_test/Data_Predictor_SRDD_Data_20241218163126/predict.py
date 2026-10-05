def predict(self, new_data):
        '''
        Predicts outcomes for new data instances.
        Ensures the model is trained before making predictions.
        '''
        if self.model is None:
            raise ValueError('Model is not trained yet.')
        if not isinstance(new_data, pd.DataFrame):
            raise ValueError('New data must be a pandas DataFrame.')
        predictions = self.model.predict(new_data)
        return predictions