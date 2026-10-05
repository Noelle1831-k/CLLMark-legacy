def main():
    print("Welcome to Data Anomaly Explorer!")
    data_importer = DataImporter()
    anomaly_detector = AnomalyDetector()
    visualizer = Visualizer()
    while True:
        print("\nOptions:")
        print("1. Import Data")
        print("2. Detect Anomalies")
        print("3. Visualize Data")
        print("4. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            file_path = input("Enter the path to your data file: ")
            data_importer.import_data(file_path)
        elif choice == '2':
            variables = input("Enter the variables to analyze (comma-separated): ").split(',')
            anomalies = anomaly_detector.detect_anomalies(data_importer.data, variables)
            print("Anomalies detected:", anomalies)
        elif choice == '3':
            visualizer.visualize(data_importer.data)
        elif choice == '4':
            print("Exiting the application.")
            sys.exit()
        else:
            print("Invalid choice. Please try again.")