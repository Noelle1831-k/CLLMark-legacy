def get_daily_intake(self):
        total_intake = 0
        today = datetime.now().strftime("%Y-%m-%d")
        for entry in self.intake_log:
            if entry["time"].startswith(today):
                total_intake += entry["amount"]
        return total_intake