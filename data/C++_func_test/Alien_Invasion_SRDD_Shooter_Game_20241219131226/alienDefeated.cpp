void Level::alienDefeated() {
    if (alienCount > 0) {
        alienCount--;
        cout << "An alien was defeated! " << alienCount << " remaining." << endl;
    }
}