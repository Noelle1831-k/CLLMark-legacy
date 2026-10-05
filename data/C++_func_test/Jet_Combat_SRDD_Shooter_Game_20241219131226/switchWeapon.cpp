void Jet::switchWeapon() {
    activeWeaponIndex = (activeWeaponIndex + 1) % weapons.size();
    cout << "Switched to weapon: " << weapons[activeWeaponIndex].getName() << endl;
}