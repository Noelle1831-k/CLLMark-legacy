bool Target::checkHit(int shotX, int shotY) {
    return (abs(x - shotX) <= 5 && abs(y - shotY) <= 5);
}