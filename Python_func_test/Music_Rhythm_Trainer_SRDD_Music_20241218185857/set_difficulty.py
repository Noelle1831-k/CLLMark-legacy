def set_difficulty(self, difficulty):
        if difficulty in self.difficulty_levels:
            self.current_difficulty = difficulty
            print(f'Difficulty set to: {difficulty}')
        else:
            print('Invalid difficulty. Defaulting to "easy".')
            self.current_difficulty = 'easy'