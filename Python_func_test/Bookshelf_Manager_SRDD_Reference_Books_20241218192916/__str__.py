def __str__(self):
        return f"Shelf: {self.name}, Books: {[book.title for book in self.books]}"