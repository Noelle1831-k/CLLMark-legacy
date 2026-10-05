bool Target::checkHit(int shotX, int shotY) const {
    return (x == shotX && y == shotY);
}