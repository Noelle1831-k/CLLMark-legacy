def add_category(self, name):
        if name in [cat.name for cat in self.categories]:
            print(f"Category '{name}' already exists.")
            return
        category = Category(name)
        self.categories.append(category)
        print(f"Category '{name}' added successfully.")