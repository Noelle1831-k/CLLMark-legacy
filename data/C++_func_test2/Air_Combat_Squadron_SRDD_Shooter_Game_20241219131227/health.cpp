Aircraft::Aircraft() : health(100), speed(10), x(0), y(0), shield(0) {
    weapons.push_back(Weapon("Machine Gun", 10));
    weapons.push_back(Weapon("Missile", 50));
}