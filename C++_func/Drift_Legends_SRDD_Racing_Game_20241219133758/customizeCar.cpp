void Car::customizeCar() {
    string customization;
    cout << "Enter customization for " << name << ": ";
    cin >> customization;
    customizations.push_back(customization);
    cout << "Customization added!" << endl;
}