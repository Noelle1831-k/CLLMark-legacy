def main():
    importer = DataImporter()
    comparator = DataComparator()
    reporter = ReportGenerator()
    # Import data sets
    dataset1 = importer.import_csv('dataset1.csv')
    dataset2 = importer.import_excel('dataset2.xlsx')
    # Compare data sets
    differences = comparator.compare_datasets(dataset1, dataset2)
    # Highlight discrepancies
    comparator.highlight_discrepancies(differences)
    # Generate and export report
    report = reporter.generate_report(differences)
    reporter.export_report(report, 'comparison_report.txt')