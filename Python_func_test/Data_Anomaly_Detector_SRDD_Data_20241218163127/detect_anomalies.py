def detect_anomalies(self, data):
        try:
            normalized_data = normalize_data(data)
            self.anomalies.extend(self.statistical_analysis(normalized_data))
            self.anomalies.extend(self.machine_learning_analysis(normalized_data))
            print(f"Anomalies detected: {len(self.anomalies)}")
        except Exception as e:
            print(f"Error detecting anomalies: {e}")
        return self.anomalies