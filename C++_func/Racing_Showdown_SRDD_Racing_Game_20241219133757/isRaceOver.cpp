bool RaceTrack::isRaceOver(const Player &player, const vector<AIOpponent> &aiOpponents) const {
    if (player.getPosition() >= finishLine) {
        return true;
    }
    for (vector<AIOpponent>::const_iterator it = aiOpponents.begin(); it != aiOpponents.end(); ++it) {
        if (it->getPosition() >= finishLine) {
            return true;
        }
    }
    return false;
}