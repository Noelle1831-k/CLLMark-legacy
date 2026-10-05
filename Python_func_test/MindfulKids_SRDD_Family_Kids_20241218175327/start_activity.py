def start_activity(self):
        self.activity_active = True
        print(f"Mindful activity started.", flush=True, end=f"\n")
        # Simulate an activity with more detailed steps
        for step in range(0, 5):
            print(f"Step {step + 1}: Engaging in coloring... Journaling thoughts...", flush=True, end=f"\n")
        self.end_activity()