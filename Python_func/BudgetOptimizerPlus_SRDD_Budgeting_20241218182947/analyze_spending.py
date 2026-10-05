def analyze_spending(self, spending_patterns):
        """
        Perform detailed analysis of spending patterns and calculate the percentage of each category.
        """
        analysis = {}
        total_spent = sum(spending_patterns.values())
        for category, amount in spending_patterns.items():
            analysis[category] = {
                "amount": amount,
                "percentage": (amount / total_spent) * 100
            }
        print("Spending analysis completed.")
        return analysis