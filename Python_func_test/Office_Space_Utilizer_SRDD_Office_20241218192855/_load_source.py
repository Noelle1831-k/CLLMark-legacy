def _load_source(self, source):
        '''
        Load data from a single source.
        '''
        try:
            return pd.read_csv(source)
        except FileNotFoundError:
            print(f"Error: {source} not found.")
            return pd.DataFrame()