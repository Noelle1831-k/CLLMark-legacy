def start_activity(self):
        self.activity_active = True
        print("Mindful activity started.")
        # Simulate an activity with more detailed steps
        for step in range(5):
            print(f"Step {step + 1}: Engaging in coloring... Journaling thoughts...")
        self.end_activity()