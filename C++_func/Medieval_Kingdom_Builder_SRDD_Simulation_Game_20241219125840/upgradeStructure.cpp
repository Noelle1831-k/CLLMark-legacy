void Kingdom::upgradeStructure(string type) {
    cout << "Upgrading " << type << "..." << endl;
    if (type == "Castle") {
        resources -= 100;
        militaryStrength += 10;
    } else if (type == "Farm") {
        resources -= 50;
        population += 5;
    } else if (type == "Market") {
        resources -= 75;
        resources += 25; 
    }
    cout << type << " upgraded successfully." << endl;
}