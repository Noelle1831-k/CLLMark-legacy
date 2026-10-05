def find_matches(self, user_profile, min_compatibility_score=1):
        '''
        Finds compatible friends for the given user profile. Filters based on a minimum compatibility score.
        Returns a sorted list of matches by compatibility score.
        '''
        if not user_profile:
            return []
        matches = []
        for name, profile in self.user_profiles.items():
            if profile != user_profile:  # Avoid matching the user with themselves
                score = self.calculate_compatibility(user_profile, profile)
                if score >= min_compatibility_score:
                    matches.append((name, score))
        # Sort matches by compatibility score in descending order
        matches.sort(key=lambda x: x[1], reverse=True)
        return [match[0] for match in matches]  # Return only the names of matches