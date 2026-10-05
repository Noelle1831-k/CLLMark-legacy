def delete_category(self, category_name):
        # Delete a category
        if category_name in self.categories:
            del self.categories[category_name]
            print(f"Category '{category_name}' deleted.")