def analyze_company_financials(self, stock):
        reports = {
            "AAPL": "Strong earnings with increasing iPhone sales.",
            "GOOG": "High ad revenue growth.",
            "AMZN": "Impressive growth in AWS services.",
            "MSFT": "Steady gains in cloud computing.",
        }
        return reports.get(stock, "No financial data available.")