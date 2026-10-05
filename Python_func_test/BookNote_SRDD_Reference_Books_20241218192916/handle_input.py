def handle_input(self, choice):
        if choice == '1':
            title = input("Enter book title: ")
            author = input("Enter author: ")
            isbn = input("Enter ISBN: ")
            self.book_manager.add_book(title, author, isbn)
        elif choice == '2':
            isbn = input("Enter ISBN to remove: ")
            self.book_manager.remove_book(isbn)
        elif choice == '3':
            isbn = input("Enter ISBN: ")
            chapter = input("Enter chapter: ")
            text = input("Enter text: ")
            highlights = input("Enter highlights: ")
            images = input("Enter images: ")
            audio = input("Enter audio: ")
            self.note_manager.add_note(isbn, chapter, text, highlights, images, audio)
        elif choice == '4':
            isbn = input("Enter ISBN: ")
            chapter = input("Enter chapter to remove: ")
            self.note_manager.remove_note(isbn, chapter)
        elif choice == '5':
            query = input("Enter search query: ")
            results = self.search_engine.search_books(query)
            for book in results:
                print(f"Title: {book.title}, Author: {book.author}, ISBN: {book.isbn}")
        elif choice == '6':
            query = input("Enter search query: ")
            results = self.search_engine.search_notes(query)
            for isbn, note in results:
                print(f"ISBN: {isbn}, Chapter: {note.chapter}, Text: {note.text}")