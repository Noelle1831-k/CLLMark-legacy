void Game::selectTrack() {
    cout << "Selecting a racing track..." << endl;
    currentTrack = make_shared<Track>("Desert Track", 5000); 
}