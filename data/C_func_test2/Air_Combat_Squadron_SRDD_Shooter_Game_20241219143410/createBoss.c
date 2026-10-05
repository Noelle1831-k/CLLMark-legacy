Boss* createBoss() {
    Boss *boss = (Boss*)malloc(sizeof(Boss));
    if (!boss) return NULL;
    boss->health = 500;
    boss->power = 100;
    boss->name = "Ultimate Boss";
    return boss;
}