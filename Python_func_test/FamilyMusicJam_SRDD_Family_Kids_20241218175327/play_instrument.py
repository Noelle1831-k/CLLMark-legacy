def play_instrument(self):
        """Allows the user to play a chosen instrument."""
        instrument = input("\nChoose instrument (keyboard, drums, guitar): ").strip().lower()
        if instrument == "keyboard":
            chord = input("Enter chord to play (e.g., C Major, G Minor): ").strip()
            self.keyboard.play_chord(chord)
        elif instrument == "drums":
            beat = input("Enter beat to play (e.g., Rock, Jazz): ").strip()
            self.drums.play_beat(beat)
        elif instrument == "guitar":
            chord = input("Enter chord to strum (e.g., G Major, D Minor): ").strip()
            self.guitar.strum_chord(chord)
        else:
            print("Unknown instrument. Please choose between keyboard, drums, or guitar.")