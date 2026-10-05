def generate_forecast_report(self, data, growth_rate=0.05):
        print("Forecast Report")
        for source, amount in data.items():
            forecasted_amount = amount * (1 + growth_rate)
            print(f"Source: {source}")
            print(f"Current Amount: {amount}")
            print(f"Forecasted Amount (next period): {forecasted_amount:.2f}")
            print("----------")