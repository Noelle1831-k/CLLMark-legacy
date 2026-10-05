void GraphVisualizer::drawGraph(const ProgressionGraph& graph) {
    cout << "=== Character Progression Graph ===" << endl;
    vector<string> graphData = graph.getGraphData();
    for (vector<string>::const_iterator it = graphData.begin(); it != graphData.end(); ++it) {
        cout << *it << endl;
    }
    cout << "===================================" << endl;
}