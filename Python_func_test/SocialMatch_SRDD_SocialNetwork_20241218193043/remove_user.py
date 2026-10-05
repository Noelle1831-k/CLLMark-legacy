def remove_user(self, user):
        '''
        Removes a user and their interests from the graph.
        '''
        if user in self.graph:
            del self.graph[user]