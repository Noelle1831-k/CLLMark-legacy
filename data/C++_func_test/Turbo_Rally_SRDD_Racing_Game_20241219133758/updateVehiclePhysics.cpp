void PhysicsEngine::updateVehiclePhysics(Vehicle* vehicle, Track* track, Weather* weather) {
    string weatherCondition = weather->getCondition();
    if (weatherCondition == "Rainy") {
        vehicle->brake(); 
    } else if (weatherCondition == "Snowy") {
        vehicle->brake(); 
    }
    vehicle->accelerate(); 
}