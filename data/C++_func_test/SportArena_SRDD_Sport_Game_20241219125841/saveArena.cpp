void FileManager::saveArena(const Arena& arena) const {
    ofstream outFile("arena.txt");
    if (outFile.is_open()) {
        outFile << arena.getName() << endl;
        outFile << arena.getLength() << endl;
        outFile << arena.getWidth() << endl;
        outFile << arena.getSeatingCapacity() << endl;
        outFile << arena.getSurfaceType() << endl;
        outFile.close();
        cout << "Arena saved successfully." << endl;
    } else {
        cout << "Unable to open file for saving." << endl;
    }
}