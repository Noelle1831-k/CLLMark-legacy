def forecast_expenses(self, categories):
        for category in categories:
            trend = category.budget * 1.05  # Simple forecast with 5% increase
            self.trends.append(trend)
            print(f"Forecast for {category.name}: {trend}")