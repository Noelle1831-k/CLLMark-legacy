def get_notes(self, isbn):
        return self.notes.get(isbn, [])