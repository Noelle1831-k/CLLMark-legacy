def play(self, user):
        print("Playing Puzzle Game...")
        words = wordlist.get_random_words(3)
        print("Solve the puzzle with these words:")
        for word in words:
            print(f"- {word}")
        user.progress += 15