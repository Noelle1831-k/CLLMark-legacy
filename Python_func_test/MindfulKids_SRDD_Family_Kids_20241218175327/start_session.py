def start_session(self):
        self.session_active = True
        print("Meditation session started.")
        # Simulate a session with more detailed steps
        for step in range(5):
            print(f"Step {step + 1}: Breathe in... Breathe out...")
        self.end_session()