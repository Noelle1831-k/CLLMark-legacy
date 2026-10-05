void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}