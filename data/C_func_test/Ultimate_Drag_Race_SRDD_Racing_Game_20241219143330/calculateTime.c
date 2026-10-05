double calculateTime(Car car, Track track) {
    return track.length / (car.acceleration * 10.0); 
}