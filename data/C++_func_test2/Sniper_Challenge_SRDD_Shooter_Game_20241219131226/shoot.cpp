bool Player::shoot() {
    return weapon.fire(aimX, aimY);
}