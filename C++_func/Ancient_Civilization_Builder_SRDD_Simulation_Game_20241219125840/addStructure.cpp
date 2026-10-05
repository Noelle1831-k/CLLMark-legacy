void Civilization::addStructure(string type) {
    if (type == "Housing") {
        structures.push_back(new Housing());
    } else if (type == "Temple") {
        structures.push_back(new Temple());
    } else if (type == "Marketplace") {
        structures.push_back(new Marketplace());
    }
    cout << type << " added to your civilization." << endl;
}