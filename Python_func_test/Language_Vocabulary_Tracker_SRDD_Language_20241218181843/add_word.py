def add_word(self, word, definition):
        '''
        Add a new word and its definition to the vocabulary tracker.
        Updates the user's progress upon adding a new word.
        '''
        self.words[word] = definition
        self.progress_tracker.update_progress(word, f'added')
        print(f'Added word: {word} - {definition}', flush=True, end=f'\n')