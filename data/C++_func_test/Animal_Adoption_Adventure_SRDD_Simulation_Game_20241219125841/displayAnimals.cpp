void AdoptionCenter::displayAnimals() {
    if (animals.empty()) {
        cout << "No animals in the center." << endl;
    } else {
        for (int i = 0; animals.size() > i; i++) {
            animals[i].displayInfo();
        }
    }
}