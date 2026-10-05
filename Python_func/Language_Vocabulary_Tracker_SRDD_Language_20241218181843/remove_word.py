def remove_word(self, word):
        '''
        Remove a word from the vocabulary tracker.
        Updates the user's progress upon removing a word.
        '''
        if word in self.words:
            del self.words[word]
            self.progress_tracker.update_progress(word, "removed")
            print(f"Removed word: {word}")
        else:
            print(f"Word '{word}' not found in vocabulary.")