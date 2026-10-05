void fireWeapon() {
    if (player.ammo > 0) {
        player.ammo--;
        printf("%s fires a missile! Remaining Ammo: %d\n", player.name, player.ammo);
    } else {
        printf("Out of Ammo! Reload Needed!\n");
    }
}