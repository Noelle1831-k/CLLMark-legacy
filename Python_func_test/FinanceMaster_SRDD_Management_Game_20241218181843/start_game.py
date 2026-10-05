def start_game(self):
        print("Welcome to the Management Game!")
        while self.running:
            self.market.update_trends()
            self.company.analyze_market(self.market)
            decision = self.get_player_decision()
            self.player.make_choice(self.company, self.finance, decision)
            self.finance.calculate_profit()
            utils.display_stats(self.company, self.finance)
            utils.random_event(self.company, self.finance)
            self.check_game_over()