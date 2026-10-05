void Resource::displayResources() {
    cout << "Displaying all resources:" << endl;
    for (int i = 0; i < resources.size(); i++) {
        cout << "Resource " << i + 1 << ": " << resources[i] << endl;
    }
}