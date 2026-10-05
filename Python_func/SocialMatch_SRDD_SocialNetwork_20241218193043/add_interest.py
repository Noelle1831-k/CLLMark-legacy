def add_interest(self, user, interest):
        '''
        Adds an interest for a user in the graph.
        '''
        if user not in self.graph:
            self.graph[user] = set()
        self.graph[user].add(interest)