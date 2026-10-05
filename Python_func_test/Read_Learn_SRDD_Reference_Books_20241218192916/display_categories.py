def display_categories(self):
        '''
        Displays all book categories and their respective titles.
        '''
        print("\nBook Categories:")
        for category, books in self.categories.items():
            print(f"- {category} ({len(books)} books)")
            for book in books:
                print(f"  * {book['title']} by {book['author']}")