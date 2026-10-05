def add_snippet(self, content, tags):
        snippet_id = ''.join(random.choices(string.ascii_letters + string.digits, k=8))
        snippet = Snippet(snippet_id, content, tags)
        self.snippets.append(snippet)