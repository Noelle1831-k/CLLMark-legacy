void fireWeapon(Weapon *weapon, Player *player) {
    if (weapon->ammo > 0) {
        weapon->ammo--;
        shootProjectile(player->position, weapon->type);
    }
}