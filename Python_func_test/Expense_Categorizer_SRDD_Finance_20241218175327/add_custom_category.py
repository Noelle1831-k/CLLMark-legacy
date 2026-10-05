def add_custom_category(self):
        '''
        Add a new custom category.
        '''
        new_category = input("Enter the name of the new category: ")
        self.category_manager.add_category(new_category)
        self.data_storage.save_categories_to_file('categories.json', self.category_manager.categories)