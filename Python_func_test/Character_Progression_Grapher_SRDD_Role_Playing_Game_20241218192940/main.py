def main():
    setup_logging()
    logging.info("Application started.")
    ui = UserInterface()
    data_manager = DataManager()
    character = Character()
    while True:
        user_choice = ui.get_user_input()
        if user_choice not in {'1', '2', '3', '4', '5', '6', '7'}:
            logging.warning("Invalid menu choice: %s", user_choice)
            print("Invalid choice! Please select a valid option.")
            continue
        try:
            if user_choice == '1':
                character.add_attribute(ui.get_attribute_input())
            elif user_choice == '2':
                character.add_skill(ui.get_skill_input())
            elif user_choice == '3':
                character.add_equipment(ui.get_equipment_input())
            elif user_choice == '4':
                data_manager.save_data(character)
            elif user_choice == '5':
                character = data_manager.load_data()
            elif user_choice == '6':
                graph_data = character.get_progression_data()
                graph_generator = GraphGenerator()
                graph = graph_generator.generate_graph(graph_data)
                ui.display_graph(graph)
            elif user_choice == '7':
                logging.info("Application exited by user.")
                break
        except Exception as e:
            logging.error("An unexpected error occurred: %s", str(e))
            print("An unexpected error occurred. Please try again.")