def save_books(self):
        '''
        Saves the current book list to a JSON file.
        '''
        try:
            with open("books.json", "w") as file:
                json.dump({"books": self.books}, file, indent=4)
            print("Books saved successfully.")
        except Exception as e:
            print(f"Error saving books: {e}")