void ThemeManager::applyTheme(const string &themeName) {
    if (predefinedThemes.find(themeName) != predefinedThemes.end()) {
        cout << "Applying theme: " << themeName << endl;
    } else {
        cout << "Theme not found!" << endl;
    }
}