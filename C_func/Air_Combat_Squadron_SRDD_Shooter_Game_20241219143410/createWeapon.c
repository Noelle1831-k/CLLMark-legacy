Weapon* createWeapon() {
    Weapon *weapon = (Weapon*)malloc(sizeof(Weapon));
    if (!weapon) return NULL;
    weapon->damage = 10;
    weapon->range = 100;
    weapon->type = "Bullet";  
    return weapon;
}