def main():
    '''
    Main function to run the Code Dependency Viewer application.
    '''
    file_manager = FileManager()
    code_analyzer = CodeAnalyzer()
    dependency_graph = DependencyGraph()
    graph_visualizer = GraphVisualizer()
    # Read and analyze source code files
    files = file_manager.list_files('src')
    for file in files:
        code_analyzer.analyze_code(file, dependency_graph)
    # Visualize the dependency graph
    graph_visualizer.visualize(dependency_graph)