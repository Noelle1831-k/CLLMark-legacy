def generate_report(self):
        print("\nLibrary Report:")
        for shelf in self.shelves:
            print(f"Shelf: {shelf.name}")
            for book in shelf.books:
                print(book)
        print("End of Report.\n")