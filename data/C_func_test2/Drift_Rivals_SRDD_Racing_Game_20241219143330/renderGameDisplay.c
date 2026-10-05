void renderGameDisplay(Car* car, Track* track, int score) {
    printf("Car Position: (%.2f, %.2f) | Speed: %.2f | Drift Angle: %.2f\n", 
            car->positionX, car->positionY, car->speed, car->driftAngle);
    printf("Track ID: %d | Score: %d\n", track->trackID, score);
}