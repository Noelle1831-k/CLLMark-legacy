def main():
    # Initialize the DataFormatter object
    formatter = DataFormatter()
    # Define the path to the input data file
    file_path = 'data/input.csv'
    # Import data from the specified file path
    formatter.import_data(file_path)
    # Define the formatting rules to be applied
    rules = {
        'change_data_types': {'column1': 'int', 'column2': 'float'},
        'rearrange_columns': ['column2', 'column1', 'column3'],
        'remove_duplicates': True,
        'merge_cells': {
            'columns': ['column1', 'column2'],
            'separator': '-',
            'merged_column_name': 'merged_data',
            'remove_original': True
        }
    }
    # Apply the formatting rules to the imported data
    formatter.apply_formatting_rules(rules)
    # Export the formatted data to the specified output file path
    formatter.export_data('data/output.csv')