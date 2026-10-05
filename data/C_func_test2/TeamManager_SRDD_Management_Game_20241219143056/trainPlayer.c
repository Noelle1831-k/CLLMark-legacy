void trainPlayer(Player *p) {
    printf("Training %s...\n", p->name);
    p->skill += randomInt(1, 5);
    p->stamina += randomInt(1, 3);
    printf("Training complete! Updated stats:\n");
    displayPlayerStats(*p);
}