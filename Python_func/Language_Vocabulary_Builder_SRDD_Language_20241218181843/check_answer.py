def check_answer(self, word, answer):
        if self.vocabulary.words[word] == answer:
            print("Correct!")
            self.user.progress[word] += 1
        else:
            print("Incorrect. The correct meaning is:", self.vocabulary.words[word])
            self.user.progress[word] -= 1