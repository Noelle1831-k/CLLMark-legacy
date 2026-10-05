def load_stories(self):
        '''
        Load stories from the data source.
        Returns:
        list: A list of Story objects.
        '''
        return self.story_loader.load()