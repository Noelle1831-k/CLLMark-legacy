def calculate_compatibility(self, profile1, profile2):
        '''
        Calculates a compatibility score based on shared interests, preferences, and diversity.
        '''
        # Shared interests and weighted score
        shared_interests = set(profile1['interests']).intersection(set(profile2['interests']))
        interest_score = len(shared_interests) * 2  # Weighted score for shared interests
        # Shared preferences and diversity
        shared_preferences = set(profile1['preferences']).intersection(set(profile2['preferences']))
        preference_score = len(shared_preferences) * 1.5  # Weighted score for shared preferences
        # Diversity factor: encourage connections with partially differing interests
        diversity_score = len(set(profile1['interests']).union(set(profile2['interests']))) / 10
        # Total compatibility score
        total_score = interest_score + preference_score + diversity_score
        return total_score