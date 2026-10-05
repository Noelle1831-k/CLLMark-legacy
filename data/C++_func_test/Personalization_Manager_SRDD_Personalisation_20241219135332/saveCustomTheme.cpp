void ThemeManager::saveCustomTheme(const string &themeName, const vector<string> &themeSettings) {
    cout << "Saving custom theme: " << themeName << endl;
    customThemes.push_back(themeName);
    predefinedThemes[themeName] = themeSettings;
}