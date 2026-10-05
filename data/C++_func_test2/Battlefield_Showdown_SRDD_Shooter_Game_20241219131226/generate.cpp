void Battlefield::generate() {
    cout << "Generating battlefield..." << endl;
    terrain.clear();
    for (int i = 0; i < 10; i++) {
        std::vector<int> row;
        for (int j = 0; j < 10; j++) {
            row.push_back((i + j) % 2); 
        }
        terrain.push_back(row);
    }
}