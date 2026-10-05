bool Weapon::fire(float targetX, float targetY) {
    if (ammo > 0) {
        --ammo;
        return Ballistics::checkCollision(targetX, targetY, Utils::randomFloat(0, 100), Utils::randomFloat(0, 100));
    }
    return false;
}