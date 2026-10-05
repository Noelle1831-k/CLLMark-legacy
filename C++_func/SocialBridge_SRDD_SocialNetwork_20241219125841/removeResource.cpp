void Resource::removeResource(string resource) {
    resources.erase(remove(resources.begin(), resources.end(), resource), resources.end());
    cout << "Resource removed: " << resource << endl;
}