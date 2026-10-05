void generateTrack(Track *track, int length) {
    track->length = length;
    track->features = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        track->features[i] = rand() % 3; 
    }
}