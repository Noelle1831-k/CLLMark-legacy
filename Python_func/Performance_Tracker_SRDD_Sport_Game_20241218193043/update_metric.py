def update_metric(self, metric_name, value):
        if metric_name == 'speed':
            self.metrics.update(speed=value)
        elif metric_name == 'agility':
            self.metrics.update(agility=value)
        elif metric_name == 'accuracy':
            self.metrics.update(accuracy=value)