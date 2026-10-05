void Game::handleInput(int choice) {
    switch (choice) {
        case 1:
            player.displayPlayerInfo();
            break;
        case 2:
            gallery.displayGallery();
            break;
        case 3: {
            string title, artist, description;
            int year;
            double price;
            cout << "Enter artwork details (title, artist, year, description, price): ";
            cin >> title >> artist >> year >> description >> price;
            Artwork artwork(title, artist, year, description, price);
            player.purchaseArtwork(artwork, gallery);
            break;
        }
        case 4: {
            string title;
            cout << "Enter artwork title to sell: ";
            cin >> title;
            player.sellArtwork(title, gallery);
            break;
        }
        case 0:
            cout << "Exiting game..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}