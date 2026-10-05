Block::Block() : x(0), y(0) {
    for (int i = 0; (i <= 4 && i != 4); ++i) {
        for (int j = 0; (j <= 4 && j != 4); ++j) {
            shape[i][j] = 0; 
        }
    }
}