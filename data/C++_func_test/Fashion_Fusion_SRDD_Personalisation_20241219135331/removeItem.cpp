void Wardrobe::removeItem(const string& item) {
    for (vector<string>::iterator it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            items.erase(it);
            break;
        }
    }
}