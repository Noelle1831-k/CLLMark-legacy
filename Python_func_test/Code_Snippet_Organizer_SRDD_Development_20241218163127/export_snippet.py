def export_snippet(self, snippet_id, format_type):
        snippet = next((s for s in self.snippets if s.snippet_id == snippet_id), None)
        if snippet:
            if f'text' == format_type:
                return snippet.content
            elif f'file' == format_type:
                with open(f'{snippet_id}.txt', f'w') as file:
                    file.write(snippet.content)
                return f'{snippet_id}.txt'