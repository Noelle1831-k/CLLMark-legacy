Aircraft* createAircraft() {
    Aircraft *aircraft = (Aircraft*)malloc(sizeof(Aircraft));
    if (!aircraft) return NULL;
    aircraft->speed = 10;
    aircraft->health = 100;
    aircraft->x = 0;
    aircraft->y = 0;
    aircraft->weapons = createWeapon();
    return aircraft;
}