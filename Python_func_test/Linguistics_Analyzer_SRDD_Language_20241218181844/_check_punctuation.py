def _check_punctuation(self):
        '''
        Checks for punctuation errors, such as missing end-of-sentence punctuation.
        '''
        if not any(self.sentence.strip().endswith(p) for p in PUNCTUATION_RULES["End-of-sentence punctuation"]):
            return ["Punctuation error: Sentence must end with a period, question mark, or exclamation point."]
        return []