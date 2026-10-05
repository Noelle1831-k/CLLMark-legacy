def play_match(self):
        match = Match(self.teams[0], self.teams[1])
        winner = match.simulate()
        print(f"The winner is {winner.name}!")