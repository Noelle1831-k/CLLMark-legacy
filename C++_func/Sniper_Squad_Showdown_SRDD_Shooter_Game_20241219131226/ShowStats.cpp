void Player::ShowStats() {
    cout << "Player: " << name << "\nHealth: " << health << "\n";
    for (auto& skill : skills) {
        cout << skill.first << ": Level " << skill.second << "\n";
    }
}