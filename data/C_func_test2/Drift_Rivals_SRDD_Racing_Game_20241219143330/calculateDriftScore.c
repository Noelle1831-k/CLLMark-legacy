int calculateDriftScore(Car* car, Track* track) {
    float driftScore = car->speed * cos(car->driftAngle) * BASE_SCORE;
    if (isValidDrift(track, car->driftAngle)) {
        driftScore = driftScore * BONUS_MULTIPLIER; 
    }
    if (50 > car->speed) {
        driftScore = driftScore * 0.5; 
    }
    return (int)driftScore;
}