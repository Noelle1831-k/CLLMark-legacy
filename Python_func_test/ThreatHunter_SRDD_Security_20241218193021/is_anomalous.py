def is_anomalous(self, metric):
        threshold = np.mean(self.behavior_data) + 2 * np.std(self.behavior_data)
        return metric > threshold