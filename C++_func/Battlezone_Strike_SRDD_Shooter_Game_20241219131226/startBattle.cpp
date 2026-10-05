void Multiplayer::startBattle() {
    if (connected) {
        cout << "Starting multiplayer battle..." << endl;
    } else {
        cout << "Not connected to server. Cannot start battle." << endl;
    }
}