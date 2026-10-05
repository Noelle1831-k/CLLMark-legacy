void Visualizer::renderWaveform(vector<float> data) {
    cout << "Rendering waveform..." << endl;
    waveform.clear();
    for (size_t i = 0; i < data.size(); i++) {
        float x = static_cast<float>(i) / data.size() * window.getSize().x;
        float y = window.getSize().y / 2 - data[i] * 100;
        waveform.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(waveform);
        window.display();
    }
}