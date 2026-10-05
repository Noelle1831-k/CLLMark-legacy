void TurnRandomizer::generateRandomOrder(vector<Player> &players) {
    srand(static_cast<unsigned>(time(0))); 
    size_t size = players.size();
    for (size_t i = 0; i < size * 3; i++) { 
        int index1 = rand() % size;
        int index2 = rand() % size;
        if (index1 != index2) {
            Player temp = players[index1];
            players[index1] = players[index2];
            players[index2] = temp;
        }
    }
    for (size_t i = 0; i < size; i++) {
        players[i].setTurnOrder(i + 1);
    }
}