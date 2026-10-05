def get_intake_summary(self):
        summary = {}
        for entry in self.intake_log:
            date = entry["time"].split(" ")[0]
            if date not in summary:
                summary[date] = 0
            summary[date] += entry["amount"]
        return summary