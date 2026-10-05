def main():
    '''
    Initialize the application components and start the user interface.
    '''
    library = Library()
    search_engine = SearchEngine(library)
    reading_list = ReadingList()
    ui = UserInterface(search_engine, reading_list)
    ui.start()