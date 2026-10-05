def update_investment_growth(self, investment_name, growth):
        if investment_name in self.investments:
            self.investments[investment_name]["growth"] += growth