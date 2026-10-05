def play(self):
        print(f"Playing a {self.difficulty} language arts game.")
        result = random.choice(["Pass", "Fail"])
        print(f"Language arts game result: {result}")
        return result