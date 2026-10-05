def main():
    # Initialize the DataExplorer instance
    explorer = DataExplorer()
    # Define the file path for the data to be imported
    file_path = 'data/sample_data.csv'
    # Import data from the specified file path
    explorer.import_data(file_path)
    # Display basic statistics and information about the data
    explorer.explore_data()
    # Apply a filter to the data based on specified criteria
    explorer.filter_data({'column': 'age', 'value': '>30'})
    # Sort the data by the 'name' column in ascending order
    explorer.sort_data('name', 'asc')
    # Group the data by the 'department' column
    explorer.group_data(['department'])
    # Aggregate the grouped data by summing the 'salary' column
    explorer.aggregate_data({'salary': 'sum'})
    # Visualize the data using various plots
    explorer.visualize_data()