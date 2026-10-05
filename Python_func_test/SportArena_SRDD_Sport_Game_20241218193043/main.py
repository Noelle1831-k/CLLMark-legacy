def main():
    ui = UserInterface()
    arena = Arena()
    customizer = ArenaCustomizer(arena)
    file_manager = FileManager()
    while True:
        choice = ui.display_menu()
        if choice == '1':
            customizer.customize_arena()
        elif choice == '2':
            file_manager.save_arena(arena)
        elif choice == '3':
            arena = file_manager.load_arena()
        elif choice == '4':
            ui.display_arena(arena)
        elif choice == '5':
            print("Exiting the application. Thank you for using the Virtual Sports Arena Customizer!")
            break
        else:
            print("Invalid choice. Please select a valid option.")