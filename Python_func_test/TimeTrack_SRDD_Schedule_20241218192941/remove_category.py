def remove_category(self, category):
        if category in self.categories:
            self.categories.remove(category)
            print(f'Category "{category}" removed.')
        else:
            print(f'Category "{category}" not found.')