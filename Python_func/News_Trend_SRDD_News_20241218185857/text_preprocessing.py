def text_preprocessing(self, text):
        '''
        Preprocess text by removing special characters.
        '''
        text = re.sub(r'[^a-zA-Z\s]', '', text)
        text = text.lower()
        return text