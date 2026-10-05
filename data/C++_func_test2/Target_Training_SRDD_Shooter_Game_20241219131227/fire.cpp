bool Weapon::fire() {
    if (ammo > 0) {
        ammo--;
        cout << "Fired a shot! Remaining ammo: " << ammo << endl;
        return true;
    } else {
        cout << "Out of ammo! Reload required!" << endl;
        return false;
    }
}