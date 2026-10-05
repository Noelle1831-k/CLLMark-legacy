def predict(self, data):
        '''
        Predicts the class of new data instances.
        '''
        try:
            predictions = self.model.predict(data)
            return predictions
        except Exception as e:
            print(f"Error predicting data: {e}")
            return None