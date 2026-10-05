def main():
    importer = DataImporter()
    detector = AnomalyDetector()
    reporter = ReportGenerator()
    dashboard = Dashboard()
    dashboard.display_dashboard()