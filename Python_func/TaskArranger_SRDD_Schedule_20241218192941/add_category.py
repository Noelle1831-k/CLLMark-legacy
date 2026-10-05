def add_category(self, category):
        if category not in self.categories:
            self.categories.append(category)
            print(f"Category '{category}' added.")
        else:
            print(f"Category '{category}' already exists.")