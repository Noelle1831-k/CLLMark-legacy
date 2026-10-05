def play(self):
        print(f"Playing a {self.difficulty} math game.")
        result = random.randint(1, 100)
        print(f"Math game result: {result}")
        return result