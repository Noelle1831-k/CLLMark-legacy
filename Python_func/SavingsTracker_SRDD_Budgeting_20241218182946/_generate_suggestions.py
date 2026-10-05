def _generate_suggestions(self):
        balance = self.user.get_balance()
        target = self.user.savings_target
        suggestions = "\nSuggestions:\n"
        if balance < target:
            suggestions += "  - Consider reducing expenses in non-essential categories.\n"
            suggestions += "  - Look for additional income opportunities.\n"
            suggestions += "  - Set smaller, incremental savings goals to stay motivated.\n"
        else:
            suggestions += "  - Great job! Maintain your current habits to stay on track.\n"
        return suggestions