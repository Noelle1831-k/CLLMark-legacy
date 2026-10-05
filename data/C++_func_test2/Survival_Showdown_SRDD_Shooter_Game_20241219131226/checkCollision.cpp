bool Arena::checkCollision(const Player &player, const Enemy &enemy) const {
    return player.getX() == enemy.getX() && player.getY() == enemy.getY();
}