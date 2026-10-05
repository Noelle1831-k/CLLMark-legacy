def display_categories(self):
        '''
        Display all available categories.
        '''
        categories = self.category_manager.get_all_categories()
        print("Categories:", categories, flush=True)