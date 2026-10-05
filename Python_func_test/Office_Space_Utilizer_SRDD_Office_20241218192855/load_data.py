def load_data(self):
        '''
        Load and preprocess data from multiple sources.
        '''
        data_frames = [self._load_source(source) for source in self.data_sources]
        combined_data = pd.concat(data_frames, axis=0, ignore_index=True)
        return self._preprocess(combined_data)