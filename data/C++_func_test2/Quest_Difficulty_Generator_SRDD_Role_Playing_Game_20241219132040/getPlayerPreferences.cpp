void Player::getPlayerPreferences() {
    cout << "Enter your skill level (1-10): ";
    cin >> skillLevel;
    while (skillLevel < 1 || skillLevel > 10) {
        cout << "Invalid input. Enter a skill level between 1 and 10: ";
        cin >> skillLevel;
    }
    cout << "Enter your quest preference (combat/exploration/puzzle): ";
    cin >> preference;
    while (preference != "combat" && preference != "exploration" && preference != "puzzle") {
        cout << "Invalid input. Enter a valid preference (combat/exploration/puzzle): ";
        cin >> preference;
    }
}