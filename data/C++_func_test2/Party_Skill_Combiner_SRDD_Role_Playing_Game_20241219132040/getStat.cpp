int Character::getStat(const string& stat) const {
    auto it = stats.find(stat);
    if (it != stats.end()) {
        return it->second;
    }
    return 0;
}