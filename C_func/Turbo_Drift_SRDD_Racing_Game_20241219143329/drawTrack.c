void drawTrack() {
    for (int i = 0; i < track.numPoints - 1; i++) {
        drawLine(track.points[i].x, track.points[i].y, track.points[i + 1].x, track.points[i + 1].y);
    }
}