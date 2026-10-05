def stop_chord(self, chord="all"):
        """Simulate stopping a chord on the guitar."""
        if chord == "all":
            print("Stopping all chords on guitar.")
        else:
            print(f"Stopping chord: {chord} on guitar.")