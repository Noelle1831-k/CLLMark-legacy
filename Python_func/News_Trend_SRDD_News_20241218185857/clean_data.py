def clean_data(self, parsed_data):
        '''
        Clean parsed data for analysis.
        '''
        print("Cleaning data...")
        return [article.lower().strip() for article in parsed_data if len(article) > 10]