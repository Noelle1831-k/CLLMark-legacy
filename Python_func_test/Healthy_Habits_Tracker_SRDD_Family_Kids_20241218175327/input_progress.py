def input_progress(self, category, progress):
        '''
        Inputs daily progress for a specific category.
        '''
        if category not in self.progress:
            self.progress[category] = []
        self.progress[category].append(progress)