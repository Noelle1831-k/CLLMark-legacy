def main():
    file_handler = FileHandler()
    book_manager = BookManager()
    note_manager = NoteManager()
    search_engine = SearchEngine(book_manager, note_manager)
    ui = UserInterface(book_manager, note_manager, search_engine, file_handler)
    # Load existing data
    book_manager.books = file_handler.load_data('books.json')
    note_manager.notes = file_handler.load_data('notes.json')
    ui.run()
    # Save data on exit
    file_handler.save_data('books.json', book_manager.books)
    file_handler.save_data('notes.json', note_manager.notes)