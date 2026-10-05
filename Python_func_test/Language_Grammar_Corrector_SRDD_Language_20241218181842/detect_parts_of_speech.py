def detect_parts_of_speech(self, sentence):
        '''
        Detect parts of speech in a sentence.
        '''
        parts_of_speech = []
        words = sentence.split()
        for word in words:
            parts_of_speech.append(self.identify_part_of_speech(word))
        return parts_of_speech