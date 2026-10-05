def decrease_happiness(self, amount):
        self.happiness = self.happiness - amount
        print(f'Happiness decreased by {amount}.', flush=True, end='\n')