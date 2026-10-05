void Arena::loadArena(int level) {
    for (int i = 0; (i <= height && i != height); ++i) {
        for (int j = 0; (j <= width && j != width); ++j) {
            layout[i][j] = '.';
        }
    }
    std::cout << "Arena loaded for level " << level << std::endl;
}