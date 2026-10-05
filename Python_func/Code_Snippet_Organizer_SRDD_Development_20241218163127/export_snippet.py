def export_snippet(self, snippet_id, format_type):
        snippet = next((s for s in self.snippets if s.snippet_id == snippet_id), None)
        if snippet:
            if format_type == "text":
                return snippet.content
            elif format_type == "file":
                with open(f"{snippet_id}.txt", "w") as file:
                    file.write(snippet.content)
                return f"{snippet_id}.txt"