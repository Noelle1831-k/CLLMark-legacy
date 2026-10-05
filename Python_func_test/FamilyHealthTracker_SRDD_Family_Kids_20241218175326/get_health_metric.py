def get_health_metric(self, metric_name):
        return self.health_metrics.get(metric_name, "Metric not found")