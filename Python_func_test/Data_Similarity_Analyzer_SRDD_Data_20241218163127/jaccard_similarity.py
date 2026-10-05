def jaccard_similarity(self, data1, data2):
        '''
        Compute Jaccard similarity between two datasets.
        '''
        try:
            intersection = len(set(data1).intersection(set(data2)))
            union = len(set(data1).union(set(data2)))
            return intersection / union
        except Exception as e:
            print(f"Error computing Jaccard similarity: {e}")
            return None