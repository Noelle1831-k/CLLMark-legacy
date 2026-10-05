void Renderer::renderBlocks(const Block blocks[]) {
    cout << "Blocks:" << endl;
    for (int k = 0; k < 5; ++k) {
        cout << "Block " << k + 1 << ":" << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << blocks[k].shape[i][j] << " ";
            }
            cout << endl;
        }
    }
}