void Player::maneuver(RaceTrack &track) {
    cout << "Maneuvering..." << endl;
    position += vehicle.getSpeed() / 10;
    track.applyObstacle(position);
}