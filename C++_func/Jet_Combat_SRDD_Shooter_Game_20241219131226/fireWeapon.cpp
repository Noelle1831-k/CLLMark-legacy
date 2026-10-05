void Jet::fireWeapon() {
    if (activeWeaponIndex < weapons.size()) {
        weapons[activeWeaponIndex].fire();
    } else {
        cout << "No weapon selected!" << endl;
    }
}