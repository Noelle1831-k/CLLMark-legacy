def add_edge(self, from_node, to_node):
        '''
        Adds an edge between nodes to represent a dependency.
        '''
        if from_node in self.edges:
            self.edges[from_node].append(to_node)
        else:
            self.edges[from_node] = [to_node]