def display_books(self):
        if self.books:
            print("Books available:")
            for book in self.books:
                print(f"- {book}")
        else:
            print("No books available for this location.")