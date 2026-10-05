def remove_chord(self, index):
        if 0 <= index < len(self.chord_sequence):
            removed = self.chord_sequence.pop(index)
            print(f"Removed chord: {removed}")
        else:
            print("Invalid index for chord removal.")