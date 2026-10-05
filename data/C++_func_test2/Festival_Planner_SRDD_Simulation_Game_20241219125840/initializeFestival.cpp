void FestivalManager::initializeFestival() {
    cout << "Initializing your festival..." << endl;
    player.chooseLocation(location);
    player.selectArtists(artists);
    cout << "Festival setup complete!" << endl;
}