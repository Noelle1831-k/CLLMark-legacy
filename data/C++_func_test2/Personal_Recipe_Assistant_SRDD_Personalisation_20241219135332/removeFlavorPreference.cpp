void UserPreferences::removeFlavorPreference(string flavor) {
    flavorPreferences.erase(remove(flavorPreferences.begin(), flavorPreferences.end(), flavor), flavorPreferences.end());
}