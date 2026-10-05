def get_manual_input(self):
        input_data = input("Enter the chord progression (e.g., C G Am F): ")
        chords = input_data.split()
        if self.validate_input(chords):
            print(f"Manual input chords: {chords}")
            return chords
        else:
            print("Invalid input.")
            return []