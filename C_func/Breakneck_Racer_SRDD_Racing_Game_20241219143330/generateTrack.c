void generateTrack(Track *track) {
    srand(time(NULL));
    track->length = 5000 + (rand() % 1000); 
    track->obstacles = 50 + (rand() % 50); 
    track->turns = 20 + (rand() % 30);     
}