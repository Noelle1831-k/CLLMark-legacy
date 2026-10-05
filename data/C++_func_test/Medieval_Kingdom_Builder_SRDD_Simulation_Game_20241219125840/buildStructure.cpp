void Kingdom::buildStructure(string type) {
    cout << "Building " << type << "..." << endl;
    if (type == "Castle") {
        resources = resources - 200;
        militaryStrength = militaryStrength + 20;
    } else if (type == "Farm") {
        resources = resources - 100;
        population = population + 10;
    } else if (type == "Market") {
        resources = resources - 150;
        resources = resources + 50; 
    }
    cout << type << " built successfully." << endl;
}