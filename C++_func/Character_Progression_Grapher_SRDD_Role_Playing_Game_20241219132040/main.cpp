int main() {
    Character character;
    ProgressionGraph progressionGraph;
    GraphVisualizer graphVisualizer;
    string attributeName, skillName, equipmentType, equipmentName;
    int attributeValue, skillLevel;
    cout << "Enter character attributes (or type 'done' to finish):" << endl;
    while (true) {
        cout << "Attribute name: ";
        cin >> attributeName;
        if (attributeName == "done") break;
        cout << "Enter value for " << attributeName << ": ";
        cin >> attributeValue;
        if (attributeValue < 0) {
            cout << "Attribute value must be non-negative. Try again." << endl;
            continue;
        }
        character.addAttribute(attributeName, attributeValue);
    }
    cout << "Enter character skills (or type 'done' to finish):" << endl;
    while (true) {
        cout << "Skill name: ";
        cin >> skillName;
        if (skillName == "done") break;
        cout << "Enter level for " << skillName << ": ";
        cin >> skillLevel;
        if (skillLevel < 0) {
            cout << "Skill level must be non-negative. Try again." << endl;
            continue;
        }
        character.addSkill(skillName, skillLevel);
    }
    cout << "Enter character equipment (or type 'done' to finish):" << endl;
    while (true) {
        cout << "Equipment type: ";
        cin >> equipmentType;
        if (equipmentType == "done") break;
        cout << "Equipment name: ";
        cin >> equipmentName;
        character.addEquipment(equipmentType, equipmentName);
    }
    progressionGraph.generateGraph(character);
    progressionGraph.customizeGraph();
    graphVisualizer.drawGraph(progressionGraph);
    return 0;
}