def remove_category(self, name):
        '''
        Remove an existing category.
        '''
        if name in self.categories:
            self.categories.remove(name)
            print(f"Category '{name}' removed successfully.")
        else:
            print(f"Category '{name}' does not exist.")