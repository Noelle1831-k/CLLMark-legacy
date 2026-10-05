void Civilization::displayStatus() {
    cout << "Civilization Status:" << endl;
    for (int i = 0; i < structures.size(); i++) {
        structures[i]->display();
    }
    resourceManager.displayResources();
}