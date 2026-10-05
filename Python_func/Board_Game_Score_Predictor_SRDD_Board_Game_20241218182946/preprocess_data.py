def preprocess_data(self, data):
        '''
        Preprocess the loaded game data.
        '''
        # Fill missing values
        data.fillna(method='ffill', inplace=True)
        # Standardize numerical features
        scaler = StandardScaler()
        numerical_features = data.select_dtypes(include=['float64', 'int64']).columns
        data[numerical_features] = scaler.fit_transform(data[numerical_features])
        return data