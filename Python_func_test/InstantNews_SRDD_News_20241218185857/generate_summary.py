def generate_summary(self, content):
        # Generate a summary of the content
        try:
            return summarize(content, word_count=50)
        except ValueError:
            return content[:150]  # Fallback to a simple truncation