void Track::generateObstacles() {
    for (int i = 0; i < complexity * 5; i++) {
        float position = static_cast<float>(rand() % 100);
        obstacles.push_back(Obstacle("Rock", position));
    }
    cout << "Obstacles generated on track: " << name << endl;
}