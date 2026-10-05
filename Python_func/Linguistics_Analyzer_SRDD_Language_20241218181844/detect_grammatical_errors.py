def detect_grammatical_errors(self):
        '''
        Detects grammatical errors in the sentence by applying various rules.
        Returns a list of detected errors.
        '''
        errors = []
        errors.extend(self._check_subject_verb_agreement())
        errors.extend(self._check_punctuation())
        errors.extend(self._check_capitalization())
        return errors