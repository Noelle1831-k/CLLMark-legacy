def calculate_metrics(self, aggregated_data):
        """Calculates various metrics from aggregated data."""
        try:
            metrics = {}
            if "github" in aggregated_data:
                metrics["github_average_review_time"] = self.calculate_average_review_time(aggregated_data["github"])
            if "gitlab" in aggregated_data:
                metrics["gitlab_average_review_time"] = self.calculate_average_review_time(aggregated_data["gitlab"])
            if "bitbucket" in aggregated_data:
                metrics["bitbucket_average_review_time"] = self.calculate_average_review_time(aggregated_data["bitbucket"])
            # Example metric for code coverage
            metrics["overall_code_coverage"] = self.calculate_code_coverage([
                {"coverage": 75}, {"coverage": 80}, {"coverage": 95}
            ])
            return metrics
        except Exception as e:
            raise ValueError