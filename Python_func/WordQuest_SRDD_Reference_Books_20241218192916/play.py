def play(self, user):
        print("Playing Word Matching Game...")
        words = wordlist.get_random_words(5)
        random.shuffle(words)
        print("Match the words:")
        for i, word in enumerate(words):
            print(f"{i+1}. {word}")
        user.progress += 10