void Civilization::upgradeStructure(string type) {
    for (int i = 0; i < structures.size(); i++) {
        if (structures[i]->getType() == type) {
            structures[i]->upgrade();
            cout << type << " upgraded." << endl;
            return;
        }
    }
    cout << "No " << type << " found to upgrade." << endl;
}