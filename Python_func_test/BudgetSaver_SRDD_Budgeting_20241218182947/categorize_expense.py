def categorize_expense(self, expense):
        # Categorize expense based on predefined categories
        categories = ["Groceries", "Utilities", "Entertainment", "Others"]
        if expense["category"] not in categories:
            expense["category"] = "Others"
        return expense