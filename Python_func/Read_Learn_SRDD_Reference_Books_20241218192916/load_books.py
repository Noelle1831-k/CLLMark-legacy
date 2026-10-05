def load_books(self):
        '''
        Loads books from a JSON file into memory.
        '''
        try:
            with open("books.json", "r") as file:
                data = json.load(file)
                self.books = data.get("books", [])
                self._build_categories()
            print("Books loaded successfully.")
        except FileNotFoundError:
            print("No books found. Starting with an empty library.")
        except json.JSONDecodeError:
            print("Error loading books. Invalid file format.")