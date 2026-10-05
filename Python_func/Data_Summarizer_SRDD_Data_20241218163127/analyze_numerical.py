def analyze_numerical(self, data):
        numerical_data = data.select_dtypes(include=['number'])
        summary = {}
        for column in numerical_data.columns:
            try:
                summary[column] = {
                    'mean': numerical_data[column].mean(),
                    'median': numerical_data[column].median(),
                    'mode': stats.mode(numerical_data[column])[0][0],
                    'range': numerical_data[column].max() - numerical_data[column].min()
                }
            except Exception as e:
                print(f"Error analyzing numerical data for column {column}: {e}")
        return summary