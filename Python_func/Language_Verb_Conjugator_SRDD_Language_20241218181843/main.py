def main():
    '''
    Main function to initialize and run the application.
    '''
    database = VerbDatabase()
    ui = UserInterface(database)
    ui.run()