void Resource::addResource() {
    cout << "Enter resource title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter resource type (e.g., video, article, book): ";
    getline(cin, type);
    cout << "Enter resource link: ";
    getline(cin, link);
    cout << "Resource added successfully!" << endl;
}