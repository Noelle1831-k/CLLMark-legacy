def generate_puzzle(self):
        self.numbers = self.rule.apply_rule()
        print(f"Puzzle for Level {self.level}: {self.numbers}", flush=True, end="\n")