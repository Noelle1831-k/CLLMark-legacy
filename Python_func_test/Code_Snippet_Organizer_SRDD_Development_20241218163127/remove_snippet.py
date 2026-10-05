def remove_snippet(self, snippet_id):
        self.snippets = [s for s in self.snippets if s.snippet_id != snippet_id]