def remove_note(self, index):
        if 0 <= index < len(self.notes):
            del self.notes[index]