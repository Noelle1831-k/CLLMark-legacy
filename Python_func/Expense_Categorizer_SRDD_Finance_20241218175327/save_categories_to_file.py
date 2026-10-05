def save_categories_to_file(self, file_path, categories):
        '''
        Save the categories to a JSON file.
        '''
        with open(file_path, 'w') as file:
            json.dump(list(categories), file)