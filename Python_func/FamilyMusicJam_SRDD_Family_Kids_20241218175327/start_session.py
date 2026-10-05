def start_session(self):
        print("Starting Family Music Jam Session...")
        self.metronome.start()
        self.track_manager.load_track("default_track")
        self.track_manager.play_track()
        # Start interactive loop for collaborative play.
        while True:
            command = input("\nEnter command (play, stop, lesson, end): ").strip().lower()
            if command == "play":
                self.play_instrument()
            elif command == "stop":
                self.stop_instrument()
            elif command == "lesson":
                self.show_music_theory_lesson()
            elif command == "end":
                print("Ending session...")
                break
            else:
                print("Unknown command, please try again.")
        self.end_session()