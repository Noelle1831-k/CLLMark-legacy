void Player::sellArtwork(const string& title, Gallery& gallery) {
    Artwork* artwork = gallery.searchArtwork(title);
    if (artwork) {
        balance += artwork->getPrice();
        gallery.removeArtwork(title);
        cout << "Sold artwork: " << title << endl;
    } else {
        cout << "Artwork not found!" << endl;
    }
}