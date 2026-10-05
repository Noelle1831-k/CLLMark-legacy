void Character::takeDamage(int damage) {
    int actualDamage = damage - defense;
    if (actualDamage < 0) actualDamage = 0;
    health -= actualDamage;
    cout << name << " takes " << actualDamage << " damage! Remaining health: " << health << endl;
}