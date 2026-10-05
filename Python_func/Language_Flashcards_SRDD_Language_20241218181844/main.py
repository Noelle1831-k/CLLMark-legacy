def main():
    '''
    Main function to initialize and run the application.
    '''
    file_handler = FileHandler('flashcards.json')
    ui = UserInterface()
    ui.deck = file_handler.load_deck()
    try:
        ui.start()
    finally:
        file_handler.save_deck(ui.deck)