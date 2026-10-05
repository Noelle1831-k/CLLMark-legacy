def remove_custom_category(self):
        '''
        Remove an existing custom category.
        '''
        category_to_remove = input("Enter the name of the category to remove: ")
        self.category_manager.remove_category(category_to_remove)
        self.data_storage.save_categories_to_file('categories.json', self.category_manager.categories)