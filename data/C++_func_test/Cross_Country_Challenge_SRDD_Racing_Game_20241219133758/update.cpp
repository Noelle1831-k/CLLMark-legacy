void Race::update() {
    cout << "Updating race..." << endl;
    updateVehiclePositions();
    handleCollisions();
    physicsEngine.calculate();
    graphicsEngine.render();
}