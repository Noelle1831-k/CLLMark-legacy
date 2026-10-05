def load_books(self, location):
        # Load books based on location
        if location.lower() == "washington, d.c.":
            self.books = ["Book A", "Book B", "Book C"]
        elif location.lower() == "london":
            self.books = ["Book D", "Book E", "Book F"]
        else:
            self.books = list()