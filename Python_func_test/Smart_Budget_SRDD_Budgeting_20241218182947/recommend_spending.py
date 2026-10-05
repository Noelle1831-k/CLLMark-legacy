def recommend_spending(self, user):
        budget = self.calculate_budget(user)
        return f"Recommended spending limit: {budget}"