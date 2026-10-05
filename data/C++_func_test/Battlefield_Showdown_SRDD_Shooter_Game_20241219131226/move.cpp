void Player::move(int x, int y) {
    this->x = x;
    this->y = y;
    cout << name << " moved to (" << x << ", " << y << ")" << endl;
}