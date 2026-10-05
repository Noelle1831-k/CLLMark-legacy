void ThemeManager::displayThemes() {
    cout << "Available Themes:" << endl;
    for (auto &theme : predefinedThemes) {
        cout << theme.first << endl;
    }
}