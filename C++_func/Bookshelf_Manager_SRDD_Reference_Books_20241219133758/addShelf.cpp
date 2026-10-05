void Library::addShelf(const string &name) { 
    for (vector<Shelf>::const_iterator it = shelves.begin(); it != shelves.end(); ++it) {
        if (it->getShelfName() == name) {
            cout << "Shelf \"" << name << "\" already exists!" << endl;
            return;
        }
    }
    shelves.push_back(Shelf(name)); 
    cout << "Shelf \"" << name << "\" added successfully." << endl;
}