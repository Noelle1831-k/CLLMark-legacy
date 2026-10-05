def calculate_score(self):
        '''
        Calculate the score based on the time taken and puzzle difficulty.
        '''
        difficulty = self.current_puzzle.difficulty
        elapsed_time = self.timer.get_elapsed_time()
        self.score.update_score(difficulty, elapsed_time)
        print(f"Score: {self.score.get_score()}")