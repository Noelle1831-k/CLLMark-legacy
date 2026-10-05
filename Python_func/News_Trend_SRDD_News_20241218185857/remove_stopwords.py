def remove_stopwords(self, text):
        '''
        Remove stopwords from the text.
        '''
        stop_words = set(stopwords.words('english'))
        words = word_tokenize(text)
        return " ".join([word for word in words if word not in stop_words])