void Colony::buildStructure() {
    if (resources >= 100) {
        cout << "Building a new structure..." << endl;
        resources -= 100;
        cout << "Structure built successfully!" << endl;
    } else {
        cout << "Not enough resources to build a structure." << endl;
    }
}