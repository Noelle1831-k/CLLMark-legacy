def check_game_over(self):
        '''
        Checks if the game is over based on the company's financial status.
        '''
        if self.company.balance < 0:
            print("Game Over! Your company went bankrupt.")
            self.running = False