void destroyAircraft(Aircraft *aircraft) {
    destroyWeapon(aircraft->weapons);
    free(aircraft);
}