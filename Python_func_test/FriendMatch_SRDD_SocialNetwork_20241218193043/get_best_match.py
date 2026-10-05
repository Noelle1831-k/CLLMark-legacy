def get_best_match(self, user_profile):
        '''
        Retrieves the single best match for a user based on the highest compatibility score.
        '''
        matches = self.find_matches(user_profile)
        if matches:
            return matches[0]  # Return the best match (highest score)
        return None