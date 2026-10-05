def list_categories(self):
        # List all categories
        print("Available categories:")
        for category, clips in self.categories.items():
            print(f"- {category} ({len(clips)} clips)")