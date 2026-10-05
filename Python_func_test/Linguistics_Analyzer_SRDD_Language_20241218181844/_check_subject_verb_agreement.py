def _check_subject_verb_agreement(self):
        '''
        Checks for subject-verb agreement errors.
        Example rule: "they" should not be used with "is".
        '''
        if "is" in self.sentence and re.search(r'\bthey\b', self.sentence, re.IGNORECASE):
            return ["Subject-verb agreement error: 'They' should not pair with 'is'."]
        return []