def update_progress(self, word, correct):
        if correct:
            self.user.progress[word] += 1
        else:
            self.user.progress[word] -= 1