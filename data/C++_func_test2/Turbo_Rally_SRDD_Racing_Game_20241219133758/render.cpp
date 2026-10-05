void GraphicsRenderer::render(Track* track, Vehicle* vehicle, Weather* weather) {
    cout << "Rendering track: " << track->getName() << endl;
    cout << "Vehicle position: " << vehicle->getPosition() << endl;
    cout << "Weather condition: " << weather->getCondition() << endl;
}