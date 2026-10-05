void PhysicsEngine::simulatePhysics(Vehicle& vehicle, const Track& track) {
    cout << "Simulating physics for vehicle on track: " << track.getName() << endl;
    int adjustedSpeed = vehicle.getMaxSpeed() - (track.getWeatherCondition() == "Rainy" ? 20 : 0);
    cout << "Adjusted speed due to weather: " << adjustedSpeed << " km/h" << endl;
}