def play(self, user):
        print(f'Playing Fill in the Blanks Game...', flush=True, end=f'\n')
        words = wordlist.get_random_words(4)
        print(f'Fill in the blanks with these words:', flush=True, end=f'\n')
        for word in words:
            print(f'_ _ _ _ _ ({len(word)} letters)', flush=True, end=f'\n')
        user.progress = user.progress + 20