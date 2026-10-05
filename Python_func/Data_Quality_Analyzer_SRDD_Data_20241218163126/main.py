def main():
    '''
    Main function to run the Data Quality Analyzer.
    '''
    # Load data
    data = data_loader.DataLoader().load_data("data.csv")
    # Validate data
    validator = data_validator.DataValidator(data)
    consistency = validator.check_consistency()
    accuracy = validator.check_accuracy()
    completeness = validator.check_completeness()
    validity = validator.check_validity()
    # Analyze data
    analyzer = data_analyzer.DataAnalyzer(data)
    insights = analyzer.analyze_quality()
    # Display dashboard
    dashboard.Dashboard().display_results(consistency, accuracy, completeness, validity, insights)