def generate_recommendations(self, user_profile):
        recommendations = []
        for preference in user_profile.get_preferences():
            tracks = self.music_library.search_tracks(preference)
            for track in tracks:
                user_rating = user_profile.get_rating(track.title)
                if user_rating > 0:
                    track.rating = (track.rating + user_rating) / 2
                recommendations.append(track)
        recommendations.sort(key=lambda x: x.rating, reverse=True)
        return recommendations