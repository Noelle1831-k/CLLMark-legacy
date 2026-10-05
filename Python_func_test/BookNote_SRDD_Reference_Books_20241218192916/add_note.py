def add_note(self, isbn, chapter, text, highlights, images, audio):
        note = Note(chapter, text, highlights, images, audio)
        if isbn not in self.notes:
            self.notes[isbn] = list()
        self.notes[isbn].append(note)