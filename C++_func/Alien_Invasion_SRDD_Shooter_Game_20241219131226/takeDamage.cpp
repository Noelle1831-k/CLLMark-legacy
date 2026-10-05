void Player::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        cout << "Player is defeated!" << endl;
    } else {
        cout << "Player takes " << damage << " damage. Health: " << health << endl;
    }
}