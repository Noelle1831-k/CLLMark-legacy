void cleanupWeapon(Weapon *weapon) {
    if (weapon != NULL) {
        free(weapon);
    }
}