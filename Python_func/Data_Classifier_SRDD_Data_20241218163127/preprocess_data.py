def preprocess_data(self, data):
        '''
        Preprocesses the input data.
        '''
        try:
            # Handle missing values
            data = data.fillna(data.mean())
            # Encode categorical variables
            label_encoders = {}
            for column in data.select_dtypes(include=['object']).columns:
                le = LabelEncoder()
                data[column] = le.fit_transform(data[column])
                label_encoders[column] = le
            # Split data into features and target
            X = data.drop('target', axis=1)
            y = data['target']
            # Standardize features
            scaler = StandardScaler()
            X_scaled = scaler.fit_transform(X)
            return X_scaled, y
        except Exception as e:
            print(f"Error preprocessing data: {e}")
            return None, None