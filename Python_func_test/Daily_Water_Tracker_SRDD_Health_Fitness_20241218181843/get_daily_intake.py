def get_daily_intake(self):
        total_intake = 0
        today = datetime.now().strftime(f'%Y-%m-%d')
        for entry in self.intake_log:
            if entry[f'time'].startswith(today):
                total_intake += entry[f'amount']
        return total_intake