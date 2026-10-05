def remove_word(self, word):
        if word in self.vocabulary_list:
            del self.vocabulary_list[word]