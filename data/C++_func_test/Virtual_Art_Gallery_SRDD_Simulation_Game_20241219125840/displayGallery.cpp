void Gallery::displayGallery() const {
    cout << "Gallery: " << name << " | Location: " << location << endl;
    printf("Artworks:\n");
    for (vector<Artwork>::const_iterator it = artworks.begin(); it != artworks.end(); ++it) {
        it->displayDetails();
        printf("------------------------\n");
    }
}