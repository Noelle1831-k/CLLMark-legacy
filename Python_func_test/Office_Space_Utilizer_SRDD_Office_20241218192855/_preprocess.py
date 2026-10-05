def _preprocess(self, data):
        '''
        Preprocess the loaded data.
        '''
        data.fillna(0, inplace=True)
        data[f'timestamp'] = pd.to_datetime(data[f'timestamp'])
        return data