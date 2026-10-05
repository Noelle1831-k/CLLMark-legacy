void upgrade_weapon(Weapon *weapon) {
    weapon->damage += 10;
    weapon->fire_rate -= 1;
    printf("Weapon %s upgraded! Damage: %d, Fire Rate: %d.\n", weapon->name, weapon->damage, weapon->fire_rate);
}