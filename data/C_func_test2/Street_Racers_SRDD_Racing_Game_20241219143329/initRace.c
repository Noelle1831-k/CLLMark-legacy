void initRace(Race *race, const char *trackName, int laps) {
    strcpy(race->trackName, trackName);
    race->laps = laps;
    race->currentLap = 0;
}