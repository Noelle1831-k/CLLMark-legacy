def main():
    while True:
        file_path = input("Enter the path to your data file (or type 'exit' to quit): ")
        if file_path.lower() == 'exit':
            print("Exiting the application. Goodbye!")
            break
        importer = DataImporter()
        data = importer.import_data(file_path)
        if data is None:
            continue  # Prompt the user again if the file format is unsupported
        analyzer = DataAnalyzer()
        numerical_summary = analyzer.analyze_numerical(data)
        categorical_summary = analyzer.analyze_categorical(data)
        generator = SummaryGenerator()
        summary = generator.generate_summary(numerical_summary, categorical_summary)
        dashboard = Dashboard()
        dashboard.display_summary(summary)