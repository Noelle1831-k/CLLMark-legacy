def play_match(self):
        print(f"Playing match between {self.team1.name} and {self.team2.name}...")
        self.result = random.choice([self.team1.name, self.team2.name, "Draw"])