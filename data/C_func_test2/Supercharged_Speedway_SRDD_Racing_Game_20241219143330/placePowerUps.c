void placePowerUps(Track *track) {
    track->powerUps = (int*)malloc(sizeof(int) * track->length);
    for (int i = 0; i < track->length; i++) {
        if (! (rand() % 5 != 0)) { 
            track->powerUps[i] = 1; 
        } else {
            track->powerUps[i] = 0;
        }
    }
}