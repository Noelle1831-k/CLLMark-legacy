def update_sources(self, new_sources):
        '''
        Updates the list of news sources.
        '''
        print("Updating news sources...")
        self.sources = [NewsSource(source) for source in new_sources]
        print(f"Updated sources: {[source.name for source in self.sources]}")