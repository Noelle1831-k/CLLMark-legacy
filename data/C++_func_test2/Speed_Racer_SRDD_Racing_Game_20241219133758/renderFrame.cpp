void Graphics::renderFrame(const Track& track, const Vehicle& vehicle, const Weather& weather) {
    cout << "Rendering frame..." << endl;
    cout << "Track: " << track.getName() << " | Weather: " << weather.getCurrentCondition() << endl;
    cout << "Vehicle: " << vehicle.getMaxSpeed() << " km/h | Acceleration: " << vehicle.getAcceleration() << endl;
}