void Car::displayCarStats() {
    cout << "Car Name: " << name << endl;
    cout << "Handling: " << handling << endl;
    cout << "Speed: " << speed << endl;
    cout << "Durability: " << durability << endl;
    cout << "Customizations: ";
    for (size_t i = 0; i < customizations.size(); i++) {
        cout << customizations[i] << " ";
    }
    cout << endl;
}