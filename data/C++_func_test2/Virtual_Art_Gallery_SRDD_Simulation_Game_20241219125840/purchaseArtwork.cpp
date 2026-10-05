void Player::purchaseArtwork(Artwork& artwork, Gallery& gallery) {
    if (balance >= artwork.getPrice()) {
        balance -= artwork.getPrice();
        gallery.addArtwork(artwork);
        cout << "Purchased artwork: " << artwork.getTitle() << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}