def add_node(self, node):
        '''
        Adds a node to the graph.
        '''
        self.nodes.add(node)
        if node not in self.edges:
            self.edges[node] = []