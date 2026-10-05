void Aircraft::fireWeapon(int weaponType) {
    if (weaponType >= 0 && weaponType < weapons.size()) {
        cout << "Firing " << weapons[weaponType].getName() << "!" << endl;
    } else {
        cout << "Invalid weapon type!" << endl;
    }
}