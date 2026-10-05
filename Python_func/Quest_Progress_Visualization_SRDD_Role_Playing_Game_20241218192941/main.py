def main():
    quest_manager = QuestManager()
    visualizer = Visualizer()
    ui = UserInterface()
    while True:
        ui.show_menu()
        choice = ui.get_user_input()
        if choice == '1':
            quest_name = ui.get_user_input("Enter quest name: ")
            objectives = ui.get_user_input("Enter objectives (comma-separated): ").split(',')
            rewards = ui.get_user_input("Enter rewards: ")
            quest_manager.add_quest(quest_name, objectives, rewards)
        elif choice == '2':
            quest_id = int(ui.get_user_input("Enter quest ID to update: "))
            completed_objectives = ui.get_user_input("Enter completed objectives (comma-separated): ").split(',')
            quest_manager.update_quest(quest_id, completed_objectives)
        elif choice == '3':
            quests = quest_manager.get_all_quests()
            visualizer.display_quests(quests)
        elif choice == '4':
            quest_id = int(ui.get_user_input("Enter quest ID to view details: "))
            quest = quest_manager.get_quest(quest_id)
            visualizer.display_quest_details(quest)
        elif choice == '5':
            break
        else:
            print("Invalid choice. Please try again.")
    visualizer.run()