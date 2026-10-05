def _build_graph(self, dependency_graph):
        '''
        Builds a networkx graph from the DependencyGraph.
        '''
        for node in dependency_graph.nodes:
            self.graph.add_node(node)
        for from_node, to_nodes in dependency_graph.edges.items():
            for to_node in to_nodes:
                self.graph.add_edge(from_node, to_node)