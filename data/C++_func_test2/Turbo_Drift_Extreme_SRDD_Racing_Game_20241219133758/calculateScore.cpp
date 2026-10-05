void Score::calculateScore(Car* car, Track* track) {
    score += car->getSpeed() / 10;  
}