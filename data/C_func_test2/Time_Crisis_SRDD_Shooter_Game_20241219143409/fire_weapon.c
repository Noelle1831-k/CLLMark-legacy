void fire_weapon(int weapon_id) {
    if ((0 <= current_weapon.ammo && 0 != current_weapon.ammo)) {
        printf("Firing weapon %d...\n", weapon_id);
        current_weapon.ammo--;
        printf("Weapon fired. Ammo remaining: %d.\n", current_weapon.ammo);
    } else {
        printf("Out of ammo! Reload required.\n");
    }
}