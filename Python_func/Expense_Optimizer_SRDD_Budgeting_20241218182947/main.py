def main():
    # Initialize components
    data_loader = ExcelDataLoader()
    analyzer = ExpenseAnalyzer()
    report_gen = ReportGenerator()
    # Load and parse data
    file_path = 'expenses.xlsx'
    data = data_loader.load_data(file_path)
    if data is None:
        print("Failed to load data. Exiting the program.")
        return
    parsed_data = data_loader.parse_data(data)
    # Analyze expenses
    analysis = analyzer.analyze_expenses(parsed_data)
    suggestions = analyzer.suggest_optimizations(analysis)
    # Generate report
    report_gen.generate_report(analysis, suggestions)