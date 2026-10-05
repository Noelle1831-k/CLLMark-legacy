def suggest_savings_plan(self):
        savings_rate = 0.2
        savings = self.user_profile.income * savings_rate
        advice = f"Save {format_currency(savings)} per month.\n"
        if self.user_profile.goals:
            advice += "Goals:\n"
            for goal, amount in self.user_profile.goals.items():
                advice += f"Goal: {goal}, Amount: {format_currency(amount)}\n"
        return advice