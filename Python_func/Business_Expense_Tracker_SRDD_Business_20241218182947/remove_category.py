def remove_category(self, category_name):
        '''
        Removes a category from the list.
        '''
        if category_name in self.categories:
            self.categories.remove(category_name)