void GameEngine::render() {
    cout << "Rendering game visuals..." << endl;
    renderer.renderTrack(raceTrack);
    renderer.renderCar(playerCar);
    renderer.renderPolice(police);
}