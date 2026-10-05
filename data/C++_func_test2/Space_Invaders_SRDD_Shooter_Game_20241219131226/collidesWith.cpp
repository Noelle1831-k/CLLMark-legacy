bool Alien::collidesWith(const GameObject& other) const {
    return (x == other.getX() && y == other.getY());
}