def calculate_next_due_date(self):
        today = datetime.date.today()
        next_due_date = self.start_date
        while next_due_date <= today:
            if self.frequency == "monthly":
                next_due_date = self._add_months(next_due_date, 1)
            elif self.frequency == "weekly":
                next_due_date += datetime.timedelta(weeks=1)
            elif self.frequency == "daily":
                next_due_date += datetime.timedelta(days=1)
            else:
                raise ValueError(f"Unsupported frequency: {self.frequency}")
        return next_due_date