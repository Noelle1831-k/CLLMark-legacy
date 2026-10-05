def analyze_market(self):
        stock = input("Enter stock symbol to analyze: ").upper()
        trend = self.analyzer.analyze_trends(stock)
        financials = self.analyzer.analyze_company_financials(stock)
        print(f"Trend Analysis: {trend}")
        print(f"Financial Report: {financials}")