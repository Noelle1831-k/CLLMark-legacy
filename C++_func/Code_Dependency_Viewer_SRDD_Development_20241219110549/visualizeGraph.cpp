void GraphVisualizer::visualizeGraph(const map<string, vector<string>>& dependencies) {
    for (map<string, vector<string>>::const_iterator it = dependencies.begin(); it != dependencies.end(); ++it) {
        cout << it->first << " depends on: ";
        for (size_t j = 0; j < it->second.size(); j++) {
            cout << it->second[j] << " ";
        }
        cout << endl;
    }
}