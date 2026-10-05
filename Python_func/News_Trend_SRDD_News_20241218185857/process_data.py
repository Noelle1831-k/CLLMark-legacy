def process_data(self, cleaned_data):
        '''
        Process cleaned data into analyzable format.
        '''
        print("Processing data...")
        utils = UtilityFunctions()
        return [utils.remove_stopwords(utils.text_preprocessing(text)) for text in cleaned_data]