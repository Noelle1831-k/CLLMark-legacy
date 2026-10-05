def main():
    '''
    Initialize and run the main loop of the application.
    '''
    quest_manager = QuestManager()
    notification_system = NotificationSystem()
    user_interface = UserInterface()
    while True:
        user_interface.display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            quest_manager.create_quest_group()
        elif choice == '2':
            quest_manager.assign_roles()
        elif choice == '3':
            quest_manager.track_progress()
        elif choice == '4':
            notification_system.schedule_notifications()
        elif choice == '5':
            user_interface.customize_categories()
        elif choice == '0':
            print("Exiting the application.")
            break
        else:
            print("Invalid choice. Please try again.")