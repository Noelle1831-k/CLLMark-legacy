void Weapon::fire() {
    if (ammo > 0) {
        ammo--;
        cout << name << " fired! Damage: " << damage << ", Remaining ammo: " << ammo << "." << endl;
    } else {
        cout << name << " is out of ammo!" << endl;
    }
}