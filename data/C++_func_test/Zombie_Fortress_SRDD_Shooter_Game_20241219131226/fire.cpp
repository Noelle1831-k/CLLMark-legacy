void Weapon::fire() {
    if (ammo > 0) {
        cout << "Firing weapon..." << endl;
        ammo--;
    } else {
        cout << "Out of ammo, reload needed!" << endl;
    }
}