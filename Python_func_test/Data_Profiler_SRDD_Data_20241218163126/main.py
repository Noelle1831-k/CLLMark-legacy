def main():
    # Initialize the DataProfiler
    profiler = DataProfiler()
    # Load data from a CSV file
    profiler.load_data('data.csv')
    # Analyze the data for types, missing values, and outliers
    profiler.analyze_data()
    # Generate a comprehensive report with statistics and visualizations
    profiler.generate_report()