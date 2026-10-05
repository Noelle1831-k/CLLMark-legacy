void Player::UpgradeSkill(string skill) {
    if (skills.find(skill) != skills.end()) {
        skills[skill]++;
        cout << skill << " upgraded to level " << skills[skill] << ".\n";
    } else {
        cout << "Invalid skill.\n";
    }
}