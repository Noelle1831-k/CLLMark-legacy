void Game::processMatches() {
    std::vector<std::pair<int, int>> matches;
    findMatches(matches);
    if (!matches.empty()) {
        clearMatches(matches);
        dropBlocks();
        fillEmptySpaces();
    }
}