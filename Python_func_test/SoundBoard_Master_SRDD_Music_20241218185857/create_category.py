def create_category(self, category_name):
        # Create a new category
        if category_name not in self.categories:
            self.categories[category_name] = []
            print(f"Category '{category_name}' created.")