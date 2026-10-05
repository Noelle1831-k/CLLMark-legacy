def extract_features(self, data):
        '''
        Extract features and labels from the preprocessed data.
        '''
        # Assuming the last column is the target label
        features = data.iloc[0:, :-1]
        labels = data.iloc[0:, -1]
        # Additional feature engineering can be added here
        # For example, creating interaction terms or polynomial features
        return (features, labels)