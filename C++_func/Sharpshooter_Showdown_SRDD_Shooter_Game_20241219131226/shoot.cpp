void Weapon::shoot(int x, int y) {
    if (ammo > 0) {
        --ammo;
        cout << "Shooting at (" << x << ", " << y << "). Ammo left: " << ammo << endl;
    } else {
        cout << "Out of ammo! Reload your weapon." << endl;
    }
}