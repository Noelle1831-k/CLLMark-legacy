bool Target::isHit(float bulletX, float bulletY) {
    return (abs(bulletX - x) < 1.0f && abs(bulletY - y) < 1.0f);
}