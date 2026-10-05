def clean_data(self, data):
        '''
        Cleans the data by handling missing values.
        Drops any rows with missing values.
        '''
        data = data.dropna()
        return data