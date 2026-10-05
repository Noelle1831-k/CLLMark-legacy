def check_badges(self):
        # Award badges based on certain criteria
        if len(self.user.expenses) >= 5:
            self.gamification.award_badge("Expense Tracker")
        if calculate_total_expenses(self.user.expenses) > 1000:
            self.gamification.award_badge("Big Spender")