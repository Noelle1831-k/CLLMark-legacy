void Visualizer::initializeGraphics() {
    cout << "Initializing graphics context..." << endl;
    window.create(sf::VideoMode(800, 600), "Music Soundwave Visualizer");
    waveform.setPrimitiveType(sf::LinesStrip);
}