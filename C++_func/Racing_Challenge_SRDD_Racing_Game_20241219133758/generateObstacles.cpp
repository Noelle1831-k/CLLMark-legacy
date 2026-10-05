void Track::generateObstacles() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, length);
    int obstacleCount = length / 100;
    for (int i = 0; i < obstacleCount; ++i) {
        obstacles.push_back(distr(eng));
    }
    cout << "Obstacles generated at positions: ";
    for (size_t i = 0; i < obstacles.size(); ++i) {
        cout << obstacles[i] << " ";
    }
    cout << endl;
}