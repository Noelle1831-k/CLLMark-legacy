def list_all_categories(self):
        categories = self.expense_manager.list_categories()
        if categories:
            print("Available Categories:")
            for category in categories:
                print(f"- {category}")
        else:
            print("No categories available. Please add some categories first.")