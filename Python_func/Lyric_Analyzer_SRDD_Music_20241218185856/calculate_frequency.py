def calculate_frequency(self, tokens):
        frequency = {}
        for word in tokens:
            if word in frequency:
                frequency[word] += 1
            else:
                frequency[word] = 1
        return frequency