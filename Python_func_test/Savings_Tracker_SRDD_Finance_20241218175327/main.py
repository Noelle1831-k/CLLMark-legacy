def main():
    ui.display_welcome_message()
    savings_manager.savings_data = data_storage.load_data_from_file('savings_data.json')
    goal_tracker.savings_goal = data_storage.load_data_from_file('savings_goal.json')
    while True:
        choice = ui.get_user_choice()
        if choice == '1':
            amount = ui.get_savings_input()
            savings_manager.add_savings(amount)
            data_storage.save_data_to_file('savings_data.json', savings_manager.savings_data)
        elif choice == '2':
            goal = ui.get_goal_input()
            goal_tracker.set_goal(goal)
            data_storage.save_data_to_file('savings_goal.json', goal_tracker.savings_goal)
        elif choice == '3':
            progress = goal_tracker.calculate_progress()
            ui.display_progress(progress)
        elif choice == '4':
            history = savings_manager.get_savings_history()
            ui.display_savings_history(history)
        elif choice == '5':
            data_visualizer.visualize_savings(savings_manager.get_savings_data())
        elif choice == '6':
            ui.display_exit_message()
            break
        else:
            ui.display_invalid_choice_message()