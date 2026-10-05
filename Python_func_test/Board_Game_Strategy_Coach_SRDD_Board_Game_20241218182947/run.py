def run(self):
        '''
        Main application loop to analyze and coach during gameplay.
        '''
        print("Welcome to the Board Game Strategy Coach!")
        while True:
            self.game_state.update_state()
            analysis = self.strategy_analyzer.analyze(self.game_state)
            recommendation = self.recommendation_engine.generate_recommendation(analysis)
            self.visualization_engine.create_visualization(recommendation)
            if self.game_rules.is_game_over(self.game_state):
                print("Game Over! Thanks for playing!")
                break
            # Prompt user to continue or exit
            user_input = input("Press Enter to continue or type 'exit' to quit: ").strip().lower()
            if user_input == 'exit':
                print("Exiting the game. Thanks for playing!")
                break