void Player::attack(Player& target) {
    cout << name << " attacks " << target.getName() << " with " << weapon.getDamage() << " damage." << endl;
}