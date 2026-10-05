void Player::takeTurn() {
    if (isAlive()) {
        move();
        attack();
        scavenge();
    }
}