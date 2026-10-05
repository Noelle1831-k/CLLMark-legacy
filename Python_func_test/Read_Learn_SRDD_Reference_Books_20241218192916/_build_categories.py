def _build_categories(self):
        '''
        Builds a mapping of categories to books.
        '''
        self.categories = {}
        for book in self.books:
            category = book.get("category", "Uncategorized")
            if category not in self.categories:
                self.categories[category] = []
            self.categories[category].append(book)