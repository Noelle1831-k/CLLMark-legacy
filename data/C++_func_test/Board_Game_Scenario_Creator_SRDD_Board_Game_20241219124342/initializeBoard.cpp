void Board::initializeBoard(int w, int h) {
    width = w;
    height = h;
    grid = vector<vector<char>>(h, vector<char>(w, '.'));
}