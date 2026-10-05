void Artwork::displayDetails() const {
    cout << "Title: " << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Year: " << year << endl;
    cout << "Description: " << description << endl;
    cout << "Category: " << category << endl;
    cout << fixed << setprecision(2) << "Price: $" << price << endl;
}