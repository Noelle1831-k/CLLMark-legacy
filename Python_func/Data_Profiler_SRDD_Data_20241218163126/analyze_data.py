def analyze_data(self):
        if self.data is not None:
            self.analyzer.analyze_data_types(self.data)
            self.analyzer.detect_missing_values(self.data)
            self.analyzer.detect_outliers(self.data)
        else:
            print("No data to analyze. Please load data first.")