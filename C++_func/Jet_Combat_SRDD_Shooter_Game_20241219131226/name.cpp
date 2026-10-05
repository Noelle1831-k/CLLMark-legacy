Jet::Jet(string name, int speed, int agility, int health)
    : name(name), speed(speed), agility(agility), health(health), activeWeaponIndex(0) {
    weapons.push_back(Weapon("Cannon", 50, 100));
    weapons.push_back(Weapon("Missile", 100, 10));
}