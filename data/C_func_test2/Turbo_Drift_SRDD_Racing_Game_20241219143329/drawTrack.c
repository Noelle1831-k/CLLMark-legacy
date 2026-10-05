void drawTrack() {
    for (int i = 0; ; ) {
        if (!((i <= track.numPoints - 1 && i != track.numPoints - 1))) {
            break;
        }
        drawLine(track.points[i].x, track.points[i].y, track.points[i + 1].x, track.points[i + 1].y);
        ++i;
    }
}