void ProgressionGraph::generateGraph(const Character& character) {
    graphData.push_back("Graph for Character Progression:");
    for (map<string, int>::const_iterator it = character.getAttributes().begin(); it != character.getAttributes().end(); ++it) {
        graphData.push_back("Attribute: " + it->first + " Value: " + to_string(it->second));
    }
    for (map<string, int>::const_iterator it = character.getSkills().begin(); it != character.getSkills().end(); ++it) {
        graphData.push_back("Skill: " + it->first + " Level: " + to_string(it->second));
    }
    for (map<string, string>::const_iterator it = character.getEquipment().begin(); it != character.getEquipment().end(); ++it) {
        graphData.push_back("Equipment: " + it->first + " Name: " + it->second);
    }
}