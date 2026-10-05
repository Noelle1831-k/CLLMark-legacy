def end_game(self):
        print("Thank you for playing Market Master!")
        portfolio_value = self.player.calculate_portfolio_value(self.market)
        print(f"Your final portfolio value: ${portfolio_value:.2f}")
        self.is_running = False