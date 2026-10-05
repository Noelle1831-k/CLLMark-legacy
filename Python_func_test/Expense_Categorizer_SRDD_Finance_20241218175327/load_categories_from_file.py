def load_categories_from_file(self, file_path, category_manager):
        '''
        Load categories from a JSON file.
        '''
        try:
            with open(file_path, 'r') as file:
                categories = json.load(file)
                for category in categories:
                    category_manager.add_category(category)
        except FileNotFoundError:
            print("No previous categories data found. Using default categories.")