def get_metric(self, user_profile, metric_name):
        user_id = user_profile.user_id
        return self.metrics_data.get(user_id, {}).get(metric_name, f'Metric not found')