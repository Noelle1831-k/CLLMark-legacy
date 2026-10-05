def main():
    wardrobe_manager = WardrobeManager()
    outfit_suggester = OutfitSuggester(wardrobe_manager)
    user_interface = UserInterface(wardrobe_manager, outfit_suggester)
    while True:
        user_interface.display_menu()
        choice = user_interface.get_user_input()
        if choice == '1':
            user_interface.add_item()
        elif choice == '2':
            user_interface.remove_item()
        elif choice == '3':
            user_interface.list_items()
        elif choice == '4':
            user_interface.suggest_outfit()
        elif choice == '5':
            break