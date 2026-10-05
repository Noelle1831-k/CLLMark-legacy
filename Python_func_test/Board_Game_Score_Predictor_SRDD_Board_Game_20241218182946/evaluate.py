def evaluate(self, predictions, labels):
        '''
        Evaluate the prediction accuracy using R^2 score.
        '''
        try:
            r2 = r2_score(labels, predictions)
        except Exception as e:
            raise Exception(f'Error during evaluation: {e}')
        return r2 * 100  # Convert to percentage for consistency