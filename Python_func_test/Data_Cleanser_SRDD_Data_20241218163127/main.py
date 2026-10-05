def main():
    data = load_data()
    while True:
        display_menu()
        option = ui.get_user_input("Select an option: ")
        data = execute_option(option, data)
        utils.log_operations(f"Option {option} executed.")