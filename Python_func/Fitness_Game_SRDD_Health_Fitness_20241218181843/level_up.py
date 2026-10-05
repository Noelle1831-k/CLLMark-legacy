def level_up(self):
        '''
        Increases the user's level based on points earned.
        '''
        if self.points >= self.level * 100:
            self.level += 1
            print(f"Congrats {self.name}! You've leveled up to level {self.level}.")