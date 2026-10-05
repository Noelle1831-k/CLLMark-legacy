void attack_tank(Tank *attacker, Tank *target) {
    printf("Tank %s attacking Tank %s for %d damage\n", attacker->type, target->type, attacker->damage);
    target->health -= attacker->damage;
    if (target->health <= 0) {
        printf("Tank %s destroyed!\n", target->type);
    }
}