def add_category(self):
        category_name = input("Enter new category name: ")
        if category_name not in self.categories:
            self.categories[category_name] = []
            print(f"Category '{category_name}' added successfully.")
        else:
            print(f"Category '{category_name}' already exists.")