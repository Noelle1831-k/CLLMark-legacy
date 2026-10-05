def remove_note(self, isbn, chapter):
        if isbn in self.notes:
            self.notes[isbn] = [note for note in self.notes[isbn] if note.chapter != chapter]