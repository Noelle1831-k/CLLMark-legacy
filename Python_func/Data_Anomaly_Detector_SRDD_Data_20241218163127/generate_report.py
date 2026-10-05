def generate_report(self):
        if self.detector.anomalies:
            report = self.reporter.generate_report(self.detector.anomalies)
            print(report)
            self.reporter.visualize_anomalies(self.detector.anomalies, self.importer.data)
        else:
            print("No anomalies detected. Please run anomaly detection first.")