void POSIdentifier::identify(const string& token) {
    if (token == "and" || token == "or" || token == "but") {
        cout << token << " -> Conjunction" << endl;
    } else if (token == "the" || token == "a" || token == "an") {
        cout << token << " -> Article" << endl;
    } else {
        cout << token << " -> Unknown (Custom logic needed)" << endl;
    }
}