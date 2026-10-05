void Player::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    cout << "Player took " << damage << " damage. Current health: " << health << "\n";
}