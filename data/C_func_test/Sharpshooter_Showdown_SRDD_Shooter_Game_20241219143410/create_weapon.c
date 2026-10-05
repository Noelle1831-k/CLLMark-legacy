Weapon* create_weapon(int id) {
    Weapon *weapon = (Weapon*)malloc(sizeof(Weapon));
    weapon->id = id;
    weapon->is_unlocked = (id == 1) ? 1 : 0;
    return weapon;
}