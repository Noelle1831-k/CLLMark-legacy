def add_category(self, name):
        '''
        Add a new custom category.
        '''
        if name not in self.categories:
            self.categories.add(name)
            print(f"Category '{name}' added successfully.")
        else:
            print(f"Category '{name}' already exists.")