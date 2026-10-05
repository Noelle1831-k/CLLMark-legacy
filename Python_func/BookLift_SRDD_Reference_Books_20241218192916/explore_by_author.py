def explore_by_author(self, user_profile):
        author_books = defaultdict(list)
        for book in self.books:
            if book.author not in user_profile.rated_books:
                author_books[book.author].append(book)
        return author_books