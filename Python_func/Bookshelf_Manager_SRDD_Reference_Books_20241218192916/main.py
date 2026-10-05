def main():
    library = Library()
    while True:
        print("\nBook Collection Management")
        print("1. Add Book")
        print("2. Add Shelf")
        print("3. Add Note to Book")
        print("4. Add Rating to Book")
        print("5. Search Books by Title")
        print("6. Filter Books by Author")
        print("7. Generate Report")
        print("8. Exit")
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
                print(f"Book '{title}' added to shelf '{shelf_name}'.")
            else:
                print("Shelf not found. Please add the shelf first.")
        elif choice == '2':
            shelf_name = input("Enter new shelf name: ")
            library.add_shelf(Shelf(shelf_name))
            print(f"Shelf '{shelf_name}' added.")
        elif choice == '3':
            title = input("Enter book title to add note: ")
            note = input("Enter note: ")
            book_found = False
            for shelf in library.shelves:
                for book in shelf.books:
                    if book.title == title:
                        book.add_note(note)
                        print(f"Note added to book '{title}'.")
                        book_found = True
            if not book_found:
                print("Book not found.")
        elif choice == '4':
            title = input("Enter book title to add rating: ")
            try:
                rating = float(input("Enter rating (0-5): "))
                book_found = False
                for shelf in library.shelves:
                    for book in shelf.books:
                        if book.title == title:
                            book.add_rating(rating)
                            print(f"Rating added to book '{title}'.")
                            book_found = True
                if not book_found:
                    print("Book not found.")
            except ValueError as e:
                print("Invalid input. Please enter a number between 0 and 5.")
        elif choice == '5':
            title = input("Enter title to search: ")
            results = library.search_books(title)
            if results:
                for book in results:
                    print(f"Found: {book.title} by {book.author}")
            else:
                print("No books found with that title.")
        elif choice == '6':
            author = input("Enter author to filter: ")
            results = library.filter_books(author)
            if results:
                for book in results:
                    print(f"Found: {book.title} by {book.author}")
            else:
                print("No books found by that author.")
        elif choice == '7':
            library.generate_report()
        elif choice == '8':
            print("Exiting the application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")