def add_category(self, category_name):
        '''
        Adds a new category to the list.
        '''
        if category_name not in self.categories:
            self.categories.append(category_name)