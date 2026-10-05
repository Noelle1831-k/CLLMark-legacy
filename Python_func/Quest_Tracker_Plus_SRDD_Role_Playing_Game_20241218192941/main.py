def main():
    quest_manager = QuestManager()
    quest_guide = QuestGuide()
    ui = UserInterface()
    reminder_system = ReminderSystem()
    category_manager = CategoryManager()
    while True:
        ui.display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            quest_manager.add_quest()
        elif choice == '2':
            quest_manager.update_quest()
        elif choice == '3':
            quest_manager.complete_quest()
        elif choice == '4':
            quest_manager.view_progress()
        elif choice == '5':
            quest_guide.get_hint()
        elif choice == '6':
            quest_guide.get_strategy()
        elif choice == '7':
            reminder_system.set_reminder()
        elif choice == '8':
            category_manager.add_category()
        elif choice == '9':
            category_manager.assign_tag()
        elif choice == '0':
            print("Exiting Quest Tracker Plus. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")