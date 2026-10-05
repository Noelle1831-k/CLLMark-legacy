def start_tour(self, location):
        library_found = False
        for lib in self.libraries:
            if lib.location.lower() == location.lower():
                library_found = True
                info = lib.get_info()
                print(info)
                self.media_viewer.load_media("360_photo", location)
                self.media_viewer.display_media()
                self.bookshelf.load_books(location)
                self.bookshelf.display_books()
                break
        if not library_found:
            print(f"No library found at location: {location}. Please try another location.")