void UIManager::handleUserInput() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            themeManager.displayThemes();
            break;
        case 2:
            wallpaperManager.browseWallpapers();
            break;
        case 3:
            screenSaverManager.previewScreenSaver("Bouncing Balls");
            break;
        case 4:
            iconManager.previewIconSet("Retro Icons");
            break;
        case 5:
            colorSchemeManager.previewColorScheme("Dark Mode");
            break;
        case 0:
            cout << "Exiting the application." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
            displayMenu();
            break;
    }
}