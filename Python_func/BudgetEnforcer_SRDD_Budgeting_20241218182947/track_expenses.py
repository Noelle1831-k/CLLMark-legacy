def track_expenses(self):
        # Simulate tracking expenses
        self.user.add_expense(100, "Groceries", "2023-10-01")
        self.user.add_expense(200, "Utilities", "2023-10-02")
        self.user.add_expense(50, "Transport", "2023-10-03")
        self.user.add_expense(150, "Entertainment", "2023-10-04")
        self.user.add_expense(300, "Rent", "2023-10-05")
        # Earn points for tracking expenses
        self.gamification.earn_points(10 * len(self.user.expenses))
        # Check and award badges
        self.check_badges()