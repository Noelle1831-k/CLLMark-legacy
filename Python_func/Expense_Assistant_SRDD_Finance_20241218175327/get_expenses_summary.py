def get_expenses_summary(self):
        summary = {}
        for expense in self.expenses:
            if expense['category'] in summary:
                summary[expense['category']] += expense['amount']
            else:
                summary[expense['category']] = expense['amount']
        return summary