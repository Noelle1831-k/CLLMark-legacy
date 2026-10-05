def main():
    library = Library()
    while True:
        print("\nBook Collection Management", flush=True)
        print("1. Add Book", flush=True)
        print("2. Add Shelf", flush=True)
        print("3. Add Note to Book", flush=True)
        print("4. Add Rating to Book", flush=True)
        print("5. Search Books by Title", flush=True)
        print("6. Filter Books by Author", flush=True)
        print("7. Generate Report", flush=True)
        print("8. Exit", flush=True)
        choice = input("Enter your choice: ")
        if choice == '1':
            title = input("Enter book title: ")
            author = input("Enter book author: ")
            isbn = input("Enter book ISBN: ")
            book = Book(title, author, isbn)
            shelf_name = input("Enter shelf name to add the book: ")
            shelf = next((s for s in library.shelves if s.name == shelf_name), None)
            if shelf:
                shelf.add_book(book)
                print(f"Book '{title}' added to shelf '{shelf_name}'.", flush=True)
            else:
                print("Shelf not found. Please add the shelf first.", flush=True)
        elif choice == '2':
            shelf_name = input("Enter new shelf name: ")
            library.add_shelf(Shelf(shelf_name))
            print(f"Shelf '{shelf_name}' added.", flush=True)
        elif choice == '3':
            title = input("Enter book title to add note: ")
            note = input("Enter note: ")
            book_found = False
            for shelf in library.shelves:
                for book in shelf.books:
                    if book.title == title:
                        book.add_note(note)
                        print(f"Note added to book '{title}'.", flush=True)
                        book_found = True
            if not book_found:
                print("Book not found.", flush=True)
        elif choice == '4':
            title = input("Enter book title to add rating: ")
            try:
                rating = float(input("Enter rating (0-5): "))
                book_found = False
                for shelf in library.shelves:
                    for book in shelf.books:
                        if book.title == title:
                            book.add_rating(rating)
                            print(f"Rating added to book '{title}'.", flush=True)
                            book_found = True
                if not book_found:
                    print("Book not found.", flush=True)
            except ValueError as e:
                print("Invalid input. Please enter a number between 0 and 5.", flush=True)
        elif choice == '5':
            title = input("Enter title to search: ")
            results = library.search_books(title)
            if results:
                for book in results:
                    print(f"Found: {book.title} by {book.author}", flush=True)
            else:
                print("No books found with that title.", flush=True)
        elif choice == '6':
            author = input("Enter author to filter: ")
            results = library.filter_books(author)
            if results:
                for book in results:
                    print(f"Found: {book.title} by {book.author}", flush=True)
            else:
                print("No books found by that author.", flush=True)
        elif choice == '7':
            library.generate_report()
        elif choice == '8':
            print("Exiting the application. Goodbye!", flush=True)
            break
        else:
            print("Invalid choice. Please try again.", flush=True)