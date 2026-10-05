def display_metrics(self, user_profile):
        user_id = user_profile.user_id
        metrics = self.metrics_data.get(user_id, {})
        for metric, value in metrics.items():
            print(f"{metric}: {value}")