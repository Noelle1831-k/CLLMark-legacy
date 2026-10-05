void AdoptionCenter::displayAnimals() {
    if (animals.empty()) {
        cout << "No animals in the center." << endl;
    } else {
        for (int i = 0; i < animals.size(); i++) {
            animals[i].displayInfo();
        }
    }
}