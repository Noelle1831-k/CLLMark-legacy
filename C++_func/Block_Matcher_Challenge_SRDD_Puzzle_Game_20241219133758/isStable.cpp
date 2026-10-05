bool Board::isStable() const {
    return findMatches().empty();
}