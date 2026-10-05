Board::Board(int rowCount, int colCount) : rows(rowCount), cols(colCount) {
    grid.resize(rows, vector<Block>(cols, Block("empty")));
    srand(time(0));
}