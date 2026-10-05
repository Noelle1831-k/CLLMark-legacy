def forecast_expenses(self, total_expenses):
        growth_rate = random.uniform(0.05, 0.15)
        forecasted_expenses = total_expenses * (1 + growth_rate)
        return forecasted_expenses