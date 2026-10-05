def _set_difficulty_level(self):
        '''
        Randomly sets the mission difficulty level based on predefined categories.
        '''
        levels = ["Easy", "Normal", "Hard", "Expert"]
        chosen_level = random.choice(levels)
        print(f"Difficulty Level: {chosen_level}")
        return chosen_level