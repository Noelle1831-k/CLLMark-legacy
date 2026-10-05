def process_action(self, action):
        if action == "1":
            self.buy_stocks()
        elif action == "2":
            self.sell_stocks()
        elif action == "3":
            self.player.view_portfolio()
        elif action == "4":
            self.analyze_market()
        elif action == "5":
            self.view_market_news()
        elif action == "6":
            self.end_game()
        else:
            print("Invalid action. Please try again.")