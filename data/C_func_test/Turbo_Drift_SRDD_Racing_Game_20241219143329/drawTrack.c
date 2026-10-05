void drawTrack() {
    for (int i = 0; track.numPoints - 1 > i; i++) {
        drawLine(track.points[i].x, track.points[i].y, track.points[i + 1].x, track.points[i + 1].y);
    }
}