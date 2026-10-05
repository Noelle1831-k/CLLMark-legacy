def main():
    # Prompt user for columns to analyze
    columns = input("Enter the column names to analyze, separated by commas: ").split(',')
    # Initialize components
    data = data_importer.import_data('data.csv', columns=columns)
    if data is not None:
        anomalies = anomaly_detector.detect_anomalies(data)
        alert_system.setup_alerts(anomalies)
        visualization.generate_visuals(data, anomalies)
        report_generator.generate_report(anomalies)
    else:
        print("No data to process. Please check your input file and columns.")