void Renderer::renderPattern(const Pattern& pattern) {
    cout << "Pattern:" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << pattern.grid[i][j] << " ";
        }
        cout << endl;
    }
}