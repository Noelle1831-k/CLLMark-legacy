def analyze_data_types(self, data):
        print(f'Analyzing data types...', flush=True, end=f'\n')
        for column in data.columns:
            print(f'Column {column} is of type {data[column].dtype}', flush=True, end=f'\n')