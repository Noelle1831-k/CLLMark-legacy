void reload_weapon(int weapon_id) {
    printf("Reloading weapon %d...\n", weapon_id);
    current_weapon.ammo = current_weapon.max_ammo;
    printf("Weapon reloaded. Ammo: %d.\n", current_weapon.ammo);
}