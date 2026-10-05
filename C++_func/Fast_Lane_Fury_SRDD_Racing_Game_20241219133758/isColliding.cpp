bool Car::isColliding() {
    if (position < 0 || position > 1000) {
        return true;
    }
    return false;
}