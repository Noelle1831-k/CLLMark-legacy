def list_goals(self):
        return [f"{name}: ${details['amount']} by {details['deadline']}" for name, details in self.goals.items()]