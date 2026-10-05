def forecast_by_category(self, expenses_by_category):
        forecasted_expenses = {}
        for category, amounts in expenses_by_category.items():
            total = sum(amounts)
            growth_rate = random.uniform(0.05, 0.15)
            forecasted_expenses[category] = total * (1 + growth_rate)
        return forecasted_expenses