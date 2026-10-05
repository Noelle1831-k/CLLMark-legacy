def update_progress(self, word, status):
        '''
        Update the progress of a word with its current status (e.g., added or removed).
        '''
        self.progress[word] = status
        print(f"Progress updated for word: {word} - Status: {status}")