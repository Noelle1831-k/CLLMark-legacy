void Leaderboard::getTopScores() const {
    std::cout << "Leaderboard:" << std::endl;
    for (const auto &entry : scores) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}