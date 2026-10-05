def calculate_similarity(self, user1, user2):
        '''
        Calculates similarity between two users based on interests.
        '''
        interests1 = self.graph.get(user1, set())
        interests2 = self.graph.get(user2, set())
        shared_interests = interests1.intersection(interests2)
        return len(shared_interests) / len(interests1.union(interests2)) if interests1.union(interests2) else 0