void AdoptionCenter::rescueAnimal(Animal a) {
    cout << "Rescuing animal: " << endl;
    a.displayInfo();
    animals.push_back(a);
}