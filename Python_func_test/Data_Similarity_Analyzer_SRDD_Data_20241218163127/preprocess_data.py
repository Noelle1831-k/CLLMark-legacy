def preprocess_data(self, data):
        '''
        Preprocess data for similarity analysis.
        '''
        try:
            data = data.dropna()
            data = data.applymap(str)
            return data
        except Exception as e:
            print(f"Error preprocessing data: {e}")
            return None