void attack(Tank *attacker, Tank *target) {
    if (rand() % 100 < 50) {
        target->health -= attacker->damage;
    }
}