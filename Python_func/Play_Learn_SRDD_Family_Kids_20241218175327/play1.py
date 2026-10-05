def play(self):
        print(f"Playing a {self.difficulty} science game.")
        result = random.choice(["Correct", "Incorrect"])
        print(f"Science game result: {result}")
        return result