def save_words(self):
        '''
        Saves the current words to a JSON file.
        '''
        with open(f'current_words.json', f'w') as file:
            json.dump(self.words, file, ensure_ascii=False, indent=4)