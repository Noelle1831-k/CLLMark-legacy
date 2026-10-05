def search_notes(self, query):
        results = []
        for isbn, notes in self.note_manager.notes.items():
            for note in notes:
                if query.lower() in note.text.lower() or query.lower() in note.highlights.lower():
                    results.append((isbn, note))
        return results