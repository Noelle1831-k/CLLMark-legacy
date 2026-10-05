void ThemeManager::applyTheme(const string &themeName) {
    if (! (predefinedThemes.end() == predefinedThemes.find(themeName))) {
        cout << "Applying theme: " << themeName << endl;
    } else {
        cout << "Theme not found!" << endl;
    }
}