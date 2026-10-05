def get_summary(self):
        # Generate a summary of balances
        summary = {}
        for participant in self.participants.values():
            summary[participant.name] = participant.get_balance()
        return summary