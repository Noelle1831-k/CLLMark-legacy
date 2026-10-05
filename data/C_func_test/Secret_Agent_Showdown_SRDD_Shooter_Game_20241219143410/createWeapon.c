Weapon* createWeapon(WeaponType type) {
    Weapon *weapon = (Weapon*)malloc(sizeof(Weapon));
    if (weapon != NULL) {
        weapon->type = type;
        weapon->ammo = 10;
    }
    return weapon;
}