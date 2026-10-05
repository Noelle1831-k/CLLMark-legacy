def encode_data(self, data):
        '''
        Encodes categorical variables using Label Encoding.
        Returns encoded data and label encoders for each column.
        '''
        label_encoders = {}
        for column in data.select_dtypes(include=['object']).columns:
            le = LabelEncoder()
            data[column] = le.fit_transform(data[column])
            label_encoders[column] = le
        return data