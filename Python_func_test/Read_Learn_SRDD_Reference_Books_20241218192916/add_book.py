def add_book(self, title, author, category):
        '''
        Adds a new book to the collection and updates categories.
        '''
        new_book = {"title": title, "author": author, "category": category}
        self.books.append(new_book)
        if category not in self.categories:
            self.categories[category] = []
        self.categories[category].append(new_book)
        print(f"Added book: {title} by {author}")