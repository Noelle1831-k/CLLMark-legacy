void AdoptionCenter::findHome() {
    if (!animals.empty()) {
        animals.back().adopt();
        animals.pop_back();
    } else {
        cout << "No animals available for adoption." << endl;
    }
}