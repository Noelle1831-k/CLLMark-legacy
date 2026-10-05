def play(self):
        print(f"Playing a {self.difficulty} science game.", flush=True, end=f"\n")
        result = random.choice([f"Correct", f"Incorrect"])
        print(f"Science game result: {result}", flush=True, end=f"\n")
        return result