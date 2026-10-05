def main():
    '''
    Initializes the application and manages user interactions.
    '''
    print("Welcome to the Vocabulary Builder!")
    current_user = user.load_user_data()
    while True:
        display_menu()
        choice = input("Enter your choice: ")
        handle_choice(choice, current_user)