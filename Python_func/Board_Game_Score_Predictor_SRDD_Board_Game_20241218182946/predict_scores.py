def predict_scores(self, features):
        '''
        Predict scores based on the extracted features.
        '''
        try:
            predictions = self.model.predict(features)
        except Exception as e:
            raise Exception(f"Error during prediction: {e}")
        return predictions