def preview_snippet(self, snippet_id):
        highlighted = self.highlight_syntax(snippet_id)
        formatted = self.format_code(snippet_id)
        return f"Highlighted:\n{highlighted}\n\nFormatted:\n{formatted}"