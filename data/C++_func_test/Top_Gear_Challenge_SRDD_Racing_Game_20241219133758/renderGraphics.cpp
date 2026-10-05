void GraphicsEngine::renderGraphics(const Car& car, const Track& track, const Timer& timer) {
    printf("Rendering graphics...\n");
    cout << "Car Position: " << car.getPosition() << "\n";
    track.displayTrack();
    cout << "Time Remaining: " << timer.getTimeRemaining() << " seconds\n";
}