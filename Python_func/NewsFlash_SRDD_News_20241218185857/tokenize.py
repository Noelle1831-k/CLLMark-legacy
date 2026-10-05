def tokenize(self, text):
        '''
        Tokenizes the input text into a list of words, removing punctuation and converting to lowercase.
        '''
        # Use regex to find words and convert to lowercase
        return re.findall(r'\b\w+\b', text.lower())