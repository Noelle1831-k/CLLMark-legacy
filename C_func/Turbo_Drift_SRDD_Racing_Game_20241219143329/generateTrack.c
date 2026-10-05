void generateTrack() {
    track.numPoints = 100;
    for (int i = 0; i < track.numPoints; i++) {
        track.points[i].x = randomFloat(0.0, 800.0);
        track.points[i].y = randomFloat(0.0, 600.0);
    }
}