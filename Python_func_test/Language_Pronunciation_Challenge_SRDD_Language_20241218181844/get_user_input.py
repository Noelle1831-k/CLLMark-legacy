def get_user_input(self):
        for recording in self.current_challenge.recordings:
            print(f"Listen to the recording: {recording}")
            user_input = input("Mimic the pronunciation: ")
            self.provide_feedback(user_input, recording)