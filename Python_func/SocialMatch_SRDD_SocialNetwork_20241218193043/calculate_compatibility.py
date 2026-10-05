def calculate_compatibility(self, other_user, interest_graph):
        '''
        Calculates compatibility with another user based on shared interests using InterestGraph.
        '''
        compatibility_score = interest_graph.calculate_similarity(self.username, other_user.username)
        return compatibility_score