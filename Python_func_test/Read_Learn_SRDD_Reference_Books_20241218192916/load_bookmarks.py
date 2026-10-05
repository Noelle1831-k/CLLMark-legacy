def load_bookmarks(self):
        '''
        Loads bookmarks from a JSON file into memory.
        '''
        try:
            with open("bookmarks.json", "r") as file:
                self.bookmarks = json.load(file).get("bookmarks", [])
            print("Bookmarks loaded successfully.")
        except FileNotFoundError:
            print("No bookmarks found. Starting with an empty list.")
        except json.JSONDecodeError:
            print("Error loading bookmarks. Invalid file format.")