void Weapon::fire() {
    if (ammo > 0) {
        std::cout << "Firing " << name << "!" << std::endl;
        --ammo;
    } else {
        std::cout << "Out of ammo!" << std::endl;
    }
}