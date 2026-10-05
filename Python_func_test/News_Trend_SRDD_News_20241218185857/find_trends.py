def find_trends(self, processed_data):
        '''
        Find trending topics using frequency analysis.
        '''
        print("Finding trends...")
        flat_data = [word for sentence in processed_data for word in sentence.split()]
        counter = Counter(flat_data)
        return counter.most_common(15)  # Top 15 trends