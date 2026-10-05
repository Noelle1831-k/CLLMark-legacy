def main():
    quest_manager = QuestManager()
    user_interface = UserInterface(quest_manager)
    progress_tracker = ProgressTracker(quest_manager)
    tips_provider = TipsProvider()
    while True:
        user_interface.display_quests()
        choice = input("Choose an option: [1] Add Quest [2] Remove Quest [3] Update Quest [4] View Tips [5] Track Progress [6] Exit: ")
        if choice == '1':
            user_interface.add_quest()
        elif choice == '2':
            user_interface.remove_quest()
        elif choice == '3':
            user_interface.update_quest()
        elif choice == '4':
            quest_id = input("Enter quest ID for tips: ")
            tips_provider.get_tips(quest_id)
        elif choice == '5':
            progress_tracker.generate_report()
        elif choice == '6':
            print("Exiting the application. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")