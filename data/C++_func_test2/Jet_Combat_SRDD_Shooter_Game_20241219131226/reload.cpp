void Weapon::reload(int ammoCount) {
    ammo += ammoCount;
    cout << name << " reloaded. Current ammo: " << ammo << "." << endl;
}