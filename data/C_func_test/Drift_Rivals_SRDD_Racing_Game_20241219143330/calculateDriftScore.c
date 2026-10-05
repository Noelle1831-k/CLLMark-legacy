int calculateDriftScore(Car* car, Track* track) {
    float driftScore = car->speed * cos(car->driftAngle) * BASE_SCORE;
    if (isValidDrift(track, car->driftAngle)) {
        driftScore *= BONUS_MULTIPLIER; 
    }
    if ((car->speed <= 50 && car->speed != 50)) {
        driftScore *= 0.5; 
    }
    return (int)driftScore;
}