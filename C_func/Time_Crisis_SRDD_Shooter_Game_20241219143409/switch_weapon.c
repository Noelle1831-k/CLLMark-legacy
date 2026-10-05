void switch_weapon(int new_weapon_id) {
    printf("Switching to weapon ID: %d.\n", new_weapon_id);
    current_weapon.id = new_weapon_id;
    current_weapon.ammo = 30;
    current_weapon.max_ammo = 30;
    current_weapon.damage = 15;  
    printf("Weapon switched to ID %d with ammo %d/%d, damage %d.\n", current_weapon.id, current_weapon.ammo, current_weapon.max_ammo, current_weapon.damage);
}