void RaceTrack::displayResults(const Player &player, const vector<AIOpponent> &aiOpponents) const {
    cout << "Displaying race results..." << endl;
    if (player.getPosition() >= finishLine) {
        cout << "Player wins!" << endl;
    } else {
        for (vector<AIOpponent>::const_iterator it = aiOpponents.begin(); it != aiOpponents.end(); ++it) {
            if (it->getPosition() >= finishLine) {
                cout << it->getName() << " wins!" << endl;
                break;
            }
        }
    }
}