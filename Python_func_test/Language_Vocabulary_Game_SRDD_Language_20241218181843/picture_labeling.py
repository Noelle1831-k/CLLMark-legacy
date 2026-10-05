def picture_labeling(self):
        print("Starting Picture Labeling Exercise...", flush=True)
        # Simulate picture labeling logic
        for _ in range(5):
            word = random.choice(self.words)
            print(f"Label the picture with: {word}", flush=True)
            input("Your answer: ")