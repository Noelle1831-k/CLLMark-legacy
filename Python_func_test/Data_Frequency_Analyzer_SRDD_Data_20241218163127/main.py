def main():
    print("Welcome to the Data Frequency Analyzer!")
    # Get file path from user
    file_path = input("Please enter the path to your Excel file: ")
    if not validate_file_path(file_path):
        print("Invalid file path. Exiting.")
        sys.exit(1)
    # Import data
    data_importer = DataImporter(file_path)
    data = data_importer.import_data()
    # Get variable to analyze from user
    variable = input("Please enter the variable you want to analyze: ")
    if not validate_variable(data, variable):
        print("Invalid variable. Exiting.")
        sys.exit(1)
    # Analyze frequency
    frequency_analyzer = FrequencyAnalyzer(data, variable)
    frequency_table = frequency_analyzer.generate_frequency_table()
    # Visualize data
    visualizer = Visualizer(frequency_table)
    visualizer.plot_histogram()
    print("Analysis complete. Thank you for using the Data Frequency Analyzer!")