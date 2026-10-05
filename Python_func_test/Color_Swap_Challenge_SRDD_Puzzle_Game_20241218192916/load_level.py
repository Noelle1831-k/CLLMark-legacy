def load_level(self):
        print(f'Loading Level {self.current_level}...', flush=True, end='\n')
        self.target_score = self.target_score + self.current_level * 50