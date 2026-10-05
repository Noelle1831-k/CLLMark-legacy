void DependencyAnalyzer::analyzeDependencies(const vector<string>& components) {
    for (size_t i = 0; i < components.size(); i++) {
        dependencies[components[i]] = vector<string>{"Dependency1", "Dependency2"};
    }
}