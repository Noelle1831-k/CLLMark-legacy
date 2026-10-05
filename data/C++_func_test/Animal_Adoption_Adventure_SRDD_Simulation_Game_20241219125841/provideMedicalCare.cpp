void AdoptionCenter::provideMedicalCare() {
    for (int i = 0; i < animals.size(); i++) {
        animals[i].receiveCare();
    }
}