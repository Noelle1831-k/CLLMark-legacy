def take_quiz(self, vocabulary):
        import random
        word = random.choice(list(vocabulary.words.keys()))
        print(f"What is the meaning of '{word}'?")
        answer = input("Your answer: ")
        if vocabulary.words[word] == answer:
            print("Correct!")
            self.progress[word] += 1
        else:
            print("Incorrect. The correct meaning is:", vocabulary.words[word])
            self.progress[word] -= 1