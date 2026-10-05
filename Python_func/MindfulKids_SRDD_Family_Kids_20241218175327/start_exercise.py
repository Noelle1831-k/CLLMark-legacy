def start_exercise(self):
        self.exercise_active = True
        print("Breathing exercise started.")
        # Simulate an exercise with more detailed steps
        for step in range(5):
            print(f"Step {step + 1}: Inhale deeply... Exhale slowly...")
        self.end_exercise()