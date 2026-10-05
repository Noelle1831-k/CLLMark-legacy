def track_investment(self, investment_name):
        investment = self.investments.get(investment_name)
        if investment:
            return f"Investment: {investment_name}, Amount: ${investment['amount']}, Growth: ${investment['growth']}"
        return "Investment not found"