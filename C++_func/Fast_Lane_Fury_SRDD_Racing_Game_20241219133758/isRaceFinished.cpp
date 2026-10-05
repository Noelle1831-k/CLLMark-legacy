bool Track::isRaceFinished(Car &car) {
    return car.getPosition() >= length;
}