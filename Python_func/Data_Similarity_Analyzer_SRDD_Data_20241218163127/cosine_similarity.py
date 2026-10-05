def cosine_similarity(self, data1, data2):
        '''
        Compute cosine similarity between two datasets.
        '''
        try:
            vectorizer = TfidfVectorizer().fit_transform([data1, data2])
            vectors = vectorizer.toarray()
            return cs(vectors)[0][1]
        except Exception as e:
            print(f"Error computing cosine similarity: {e}")
            return None