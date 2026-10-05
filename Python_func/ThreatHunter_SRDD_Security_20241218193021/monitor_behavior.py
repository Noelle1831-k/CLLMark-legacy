def monitor_behavior(self):
        print("Monitoring user behavior...")
        for _ in range(100):
            behavior_metric = random.random()
            self.behavior_data.append(behavior_metric)
            if self.is_anomalous(behavior_metric):
                print(f"Anomaly detected: {behavior_metric}")