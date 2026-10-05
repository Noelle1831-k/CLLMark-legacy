def find_matches(self, user_profile):
        matches = []
        for profile in self.user_profiles:
            if profile != user_profile:
                compatibility_score = self.calculate_compatibility(user_profile, profile)
                if compatibility_score >= self.compatibility_threshold:
                    matches.append(profile)
        return matches