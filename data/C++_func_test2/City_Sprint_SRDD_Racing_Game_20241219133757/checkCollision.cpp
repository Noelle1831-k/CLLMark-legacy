bool Track::checkCollision(float x, float y) const {
    for (unsigned int i = 0; i < obstacles.size(); i++) {
        if (std::abs(x - obstacles[i].first) < 1.0f && std::abs(y - obstacles[i].second) < 1.0f) {
            return true;
        }
    }
    return false;
}