def save_data(self, user, savings_tracker):
        """
        Save user data, spending patterns, and savings goal progress to the database.
        """
        self.data['user_spending_data'] = user.spending_data
        self.data['user_spending_patterns'] = user.spending_patterns
        self.data['savings_goal'] = savings_tracker.savings_goal
        self.data['current_savings'] = savings_tracker.current_savings
        print("Data saved to database.")