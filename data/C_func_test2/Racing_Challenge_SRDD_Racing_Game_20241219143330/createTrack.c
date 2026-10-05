Track *createTrack(int length, int numObstacles, int numBoosters) {
    Track *track = (Track *)malloc(sizeof(Track));
    track->length = length;
    track->obstacles = (int *)malloc(numObstacles * sizeof(int));
    track->boosters = (int *)malloc(numBoosters * sizeof(int));
    for (int i = 0; i < numObstacles; i++) {
        track->obstacles[i] = rand() % length;
    }
    for (int i = 0; i < numBoosters; i++) {
        track->boosters[i] = rand() % length;
    }
    return track;
}