def create_category(self, category):
        for book in self.books:
            if category not in book.categories:
                book.categories.append(category)