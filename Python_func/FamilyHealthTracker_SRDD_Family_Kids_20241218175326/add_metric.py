def add_metric(self, user_profile, metric_name, value):
        user_id = user_profile.user_id
        if user_id not in self.metrics_data:
            self.metrics_data[user_id] = {}
        self.metrics_data[user_id][metric_name] = value