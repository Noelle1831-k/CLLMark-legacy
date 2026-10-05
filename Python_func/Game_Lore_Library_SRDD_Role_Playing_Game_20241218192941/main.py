def main():
    '''
    Main function to run the application.
    '''
    print("Welcome to the Game Lore Explorer!")
    data_store = storage.DataStore()
    user_interface = ui.UserInterface(data_store)
    while True:
        user_interface.display_main_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            user_interface.view_characters()
        elif choice == '2':
            user_interface.view_locations()
        elif choice == '3':
            user_interface.view_factions()
        elif choice == '4':
            user_interface.view_events()
        elif choice == '5':
            print("Exiting the application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")