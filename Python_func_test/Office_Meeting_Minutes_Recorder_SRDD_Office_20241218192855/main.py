def main():
    meetings = load_meetings()
    while True:
        display_menu()
        choice = get_user_input("Select an option: ")
        if choice == '1':
            create_meeting(meetings)
        elif choice == '2':
            view_meetings(meetings)
        elif choice == '3':
            print("Exiting the application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")