def play(self):
        print(f"Playing a {self.difficulty} critical thinking game.", flush=True)
        result = random.choice(["Solved", "Unsolved"])
        print(f"Critical thinking game result: {result}", flush=True)
        return result