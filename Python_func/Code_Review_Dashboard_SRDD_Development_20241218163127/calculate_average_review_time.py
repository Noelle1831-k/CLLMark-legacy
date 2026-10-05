def calculate_average_review_time(self, reviews):
        """Calculates the average review time from a list of reviews."""
        try:
            review_times = [
                (review["updated_at"] - review["created_at"]).total_seconds()
                for review in reviews
                if "updated_at" in review and "created_at" in review
            ]
            return statistics.mean(review_times) if review_times else 0
        except Exception as e:
            raise ValueError(f"Error calculating average review time: {e}")