def main():
    ui = UserInterface()
    manager = WallpaperManager()
    manager.load_wallpapers()
    while True:
        ui.display_menu()
        choice = ui.get_user_input()
        if choice == '1':
            manager.schedule_wallpaper_change()
        elif choice == '2':
            manager.set_wallpaper()
        elif choice == '3':
            break