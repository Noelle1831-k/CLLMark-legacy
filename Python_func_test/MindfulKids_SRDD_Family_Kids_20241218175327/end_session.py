def end_session(self):
        self.session_active = False
        print("Meditation session ended.", flush=True)