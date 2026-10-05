def analyze_categorical(self, data):
        categorical_data = data.select_dtypes(include=['object'])
        summary = {}
        for column in categorical_data.columns:
            try:
                summary[column] = categorical_data[column].value_counts().to_dict()
            except Exception as e:
                print(f"Error analyzing categorical data for column {column}: {e}")
        return summary