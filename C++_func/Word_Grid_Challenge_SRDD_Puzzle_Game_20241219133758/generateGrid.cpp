void Grid::generateGrid(int size) {
    srand(time(0));
    grid.resize(size, std::vector<char>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 'A' + rand() % 26;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}