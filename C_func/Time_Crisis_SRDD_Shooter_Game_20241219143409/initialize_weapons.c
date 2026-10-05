void initialize_weapons() {
    printf("Initializing weapons...\n");
    current_weapon.id = 1;
    current_weapon.ammo = 30;
    current_weapon.max_ammo = 30;
    current_weapon.damage = 10;
    printf("Weapon initialized with ID %d, ammo %d/%d, damage %d.\n", current_weapon.id, current_weapon.ammo, current_weapon.max_ammo, current_weapon.damage);
}