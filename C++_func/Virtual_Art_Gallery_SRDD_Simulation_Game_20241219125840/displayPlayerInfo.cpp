void Player::displayPlayerInfo() const {
    cout << "Player: " << name << endl;
    cout << fixed << setprecision(2) << "Balance: $" << balance << endl;
}