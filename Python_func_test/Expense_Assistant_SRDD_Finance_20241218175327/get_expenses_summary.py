def get_expenses_summary(self):
        summary = {}
        for expense in self.expenses:
            if expense[f'category'] in summary:
                summary[expense[f'category']] += expense[f'amount']
            else:
                summary[expense[f'category']] = expense[f'amount']
        return summary