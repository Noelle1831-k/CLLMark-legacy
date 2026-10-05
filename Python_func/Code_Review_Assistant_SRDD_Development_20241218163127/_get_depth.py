def _get_depth(self, node, level=0):
        '''
        Helper function to get the depth of a node.
        '''
        if not hasattr(node, 'body'):
            return level
        return max(self._get_depth(child, level + 1) for child in node.body)