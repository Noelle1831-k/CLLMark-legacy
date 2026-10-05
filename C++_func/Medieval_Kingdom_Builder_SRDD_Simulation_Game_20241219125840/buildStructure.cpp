void Kingdom::buildStructure(string type) {
    cout << "Building " << type << "..." << endl;
    if (type == "Castle") {
        resources -= 200;
        militaryStrength += 20;
    } else if (type == "Farm") {
        resources -= 100;
        population += 10;
    } else if (type == "Market") {
        resources -= 150;
        resources += 50; 
    }
    cout << type << " built successfully." << endl;
}