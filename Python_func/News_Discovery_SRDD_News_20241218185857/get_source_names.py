def get_source_names(self):
        '''
        Retrieves the names of all configured news sources.
        '''
        return [source.name for source in self.sources]