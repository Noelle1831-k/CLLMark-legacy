def filter_nodes(self, graph, criteria):
        '''
        Filters nodes based on certain criteria.
        '''
        filtered_nodes = {node for node in graph.nodes if criteria(node)}
        return filtered_nodes