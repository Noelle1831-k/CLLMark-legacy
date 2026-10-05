def analyze_trends(self, stock):
        data = self.historical_data.get(stock)
        if data:
            trend = "upward" if data[-1] > data[0] else "downward"
            return f"The trend for {stock} is {trend}."
        else:
            return f"No historical data available for {stock}."