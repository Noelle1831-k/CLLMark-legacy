def search_snippets(self, query):
        return [s for s in self.snippets if query in s.content or query in s.tags]