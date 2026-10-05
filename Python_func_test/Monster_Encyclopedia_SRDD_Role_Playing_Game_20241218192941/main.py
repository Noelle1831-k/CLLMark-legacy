def main():
    '''
    Main function to initialize and run the application.
    '''
    database = MonsterDatabase()
    ui = UserInterface(database)
    ui.run()