def get_progress(self, category):
        '''
        Retrieves progress for a specific category.
        '''
        return self.progress.get(category, [])