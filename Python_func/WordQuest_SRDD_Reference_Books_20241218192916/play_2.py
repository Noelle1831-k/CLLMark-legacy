def play(self, user):
        print("Playing Fill in the Blanks Game...")
        words = wordlist.get_random_words(4)
        print("Fill in the blanks with these words:")
        for word in words:
            print(f"_ _ _ _ _ ({len(word)} letters)")
        user.progress += 20