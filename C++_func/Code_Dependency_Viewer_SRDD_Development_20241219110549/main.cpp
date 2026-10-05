int main() {
    FileParser parser;
    DependencyAnalyzer analyzer;
    GraphVisualizer visualizer;
    Filter filter;
    Search search;
    Zoom zoom;
    string filePath = "example.cpp";
    vector<string> components = parser.parseFile(filePath);
    analyzer.analyzeDependencies(components);
    map<string, vector<string>> dependencies = analyzer.getDependencies();
    vector<string> filteredComponents = filter.applyFilter(components, "class");
    vector<string> searchResults = search.searchComponents(components, "MyClass");
    visualizer.visualizeGraph(dependencies);
    zoom.zoomIn();
    zoom.zoomOut();
    return 0;
}