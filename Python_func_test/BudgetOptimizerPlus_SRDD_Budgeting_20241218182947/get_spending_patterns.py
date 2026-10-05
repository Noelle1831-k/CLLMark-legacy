def get_spending_patterns(self):
        """
        Analyze spending patterns and categorize them.
        """
        print("Analyzing spending patterns...")
        for i, category in enumerate(self.categories):
            if i < len(self.spending_data):
                self.spending_patterns[category] = self.spending_data[i]
        print("Spending patterns analyzed.")
        return self.spending_patterns