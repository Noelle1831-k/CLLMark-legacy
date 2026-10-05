Track createTrack(int trackID) {
    Track track;
    track.trackID = trackID;
    track.numSegments = NUM_SEGMENTS;
    for (int i = 0; i < NUM_SEGMENTS; i++) {
        track.segmentAngles[i] = (rand() % 360) - 180; 
    }
    return track;
}