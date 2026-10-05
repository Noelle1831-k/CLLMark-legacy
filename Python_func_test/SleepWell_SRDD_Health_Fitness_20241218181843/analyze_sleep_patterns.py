def analyze_sleep_patterns(self, user):
        data = self.get_sleep_data(user)
        if not data:
            return "No data available"
        avg_sleep = sum(data) / len(data)
        return f"Average sleep: {avg_sleep} hours"