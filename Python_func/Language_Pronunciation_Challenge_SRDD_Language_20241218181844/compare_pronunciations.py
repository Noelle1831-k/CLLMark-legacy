def compare_pronunciations(self, native_text, user_text):
        # A simple similarity measure (could be enhanced with more sophisticated algorithms)
        native_words = native_text.split()
        user_words = user_text.split()
        matches = sum(1 for nw, uw in zip(native_words, user_words) if nw == uw)
        return matches / max(len(native_words), len(user_words))