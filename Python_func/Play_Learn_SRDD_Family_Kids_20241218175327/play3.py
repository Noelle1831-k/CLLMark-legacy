def play(self):
        print(f"Playing a {self.difficulty} critical thinking game.")
        result = random.choice(["Solved", "Unsolved"])
        print(f"Critical thinking game result: {result}")
        return result