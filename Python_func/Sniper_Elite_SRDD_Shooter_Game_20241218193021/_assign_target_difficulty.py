def _assign_target_difficulty(self):
        '''
        Assigns difficulty levels to each target based on the mission's overall difficulty.
        '''
        for target in self.targets:
            if self.difficulty_level == "Easy":
                target.set_difficulty("Low")
            elif self.difficulty_level == "Normal":
                target.set_difficulty("Medium")
            elif self.difficulty_level == "Hard":
                target.set_difficulty("High")
            else:  # Expert
                target.set_difficulty("Extreme")