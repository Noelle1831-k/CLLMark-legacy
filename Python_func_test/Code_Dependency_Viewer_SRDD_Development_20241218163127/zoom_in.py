def zoom_in(self, graph, node):
        '''
        Zooms into a specific part of the graph.
        '''
        if node in graph.edges:
            return graph.edges[node]
        return []