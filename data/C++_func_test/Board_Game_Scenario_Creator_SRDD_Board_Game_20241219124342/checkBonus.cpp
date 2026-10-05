bool Bonus::checkBonus(int x, int y) {
    for (int i = 0; i < bonusPositions.size(); i++) {
        if (bonusPositions[i].first == x && bonusPositions[i].second == y) {
            return true;
        }
    }
    return false;
}