def _preprocess(self, data):
        '''
        Preprocess the loaded data.
        '''
        data.fillna(0, inplace=True)
        data['timestamp'] = pd.to_datetime(data['timestamp'])
        return data