Board::Board() : rows(8), cols(8) {
    grid.resize(rows, vector<Block>(cols));
}