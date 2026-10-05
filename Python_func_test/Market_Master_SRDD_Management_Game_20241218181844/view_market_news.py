def view_market_news(self):
        news = self.market.get_market_news()
        print(f"Market News: {news}")