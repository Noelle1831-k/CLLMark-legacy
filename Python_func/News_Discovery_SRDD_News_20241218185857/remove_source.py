def remove_source(self, source_name):
        '''
        Removes a news source from the list.
        '''
        print(f"Removing source: {source_name}...")
        self.sources = [source for source in self.sources if source.name != source_name]
        print(f"Remaining sources: {[source.name for source in self.sources]}")