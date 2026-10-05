def analyze_data_types(self, data):
        print("Analyzing data types...")
        for column in data.columns:
            print(f"Column {column} is of type {data[column].dtype}")