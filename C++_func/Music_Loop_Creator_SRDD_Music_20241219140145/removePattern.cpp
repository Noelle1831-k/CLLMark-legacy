void GridLayout::removePattern() {
    if (!grid.empty()) {
        grid.pop_back();
        cout << "Pattern removed from grid." << endl;
    }
}