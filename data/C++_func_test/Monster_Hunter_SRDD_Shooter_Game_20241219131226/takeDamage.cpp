void Player::takeDamage(int damage) {
    health -= damage;
    cout << "Player took " << damage << " damage! Remaining health: " << health << endl;
}