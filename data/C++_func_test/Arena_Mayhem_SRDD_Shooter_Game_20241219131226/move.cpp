void Player::move(int dx, int dy) {
    x += dx * speed;
    y += dy * speed;
    std::cout << "Player moved to position (" << x << ", " << y << ")" << std::endl;
}