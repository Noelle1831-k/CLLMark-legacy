void initializeMission(Mission *mission, const char *location, const char *objective) {
    strncpy(mission->location, location, sizeof(mission->location));
    strncpy(mission->objective, objective, sizeof(mission->objective));
    mission->completed = 0;
}