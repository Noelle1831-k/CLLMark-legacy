def visualize(self, dependency_graph):
        '''
        Visualizes the dependency graph using matplotlib and networkx.
        '''
        self._build_graph(dependency_graph)
        pos = nx.spring_layout(self.graph)
        plt.figure(figsize=(12, 8))
        nx.draw(self.graph, pos, with_labels=True, node_size=2000, node_color='lightblue', font_size=10, font_weight='bold', arrowsize=20)
        plt.title('Code Dependency Graph')
        plt.show()