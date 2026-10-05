void reset_tank(Tank *tank) {
    printf("Resetting tank %s to initial state\n", tank->type);
    tank->health = 100;
    tank->speed = 1.0f;
    tank->damage = 10;
    memset(tank->powerUps, 0, sizeof(tank->powerUps));
    tank->position[0] = 0.0f;
    tank->position[1] = 0.0f;
}