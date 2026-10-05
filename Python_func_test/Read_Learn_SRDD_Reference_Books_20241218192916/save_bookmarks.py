def save_bookmarks(self):
        '''
        Saves the current bookmark list to a JSON file.
        '''
        try:
            with open("bookmarks.json", "w") as file:
                json.dump({"bookmarks": self.bookmarks}, file, indent=4)
            print("Bookmarks saved successfully.")
        except Exception as e:
            print(f"Error saving bookmarks: {e}")