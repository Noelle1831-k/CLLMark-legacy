def run(self):
        # Simulate user interaction
        self.user_profile.add_preference("Rock")
        self.user_profile.add_preference("Jazz")
        self.user_profile.rate_track("Bohemian Rhapsody", 5)
        self.user_profile.rate_track("Take Five", 4)
        self.music_library.add_track("Bohemian Rhapsody", "Queen", "Rock", 5)
        self.music_library.add_track("Take Five", "Dave Brubeck", "Jazz", 4)
        self.music_library.add_track("Stairway to Heaven", "Led Zeppelin", "Rock", 5)
        self.music_library.add_track("So What", "Miles Davis", "Jazz", 4)
        recommendations = self.recommendation_engine.generate_recommendations(self.user_profile)
        print("Recommended Tracks:")
        for track in recommendations:
            print(f"{track.title} by {track.artist} (Genre: {track.genre}, Rating: {track.rating})")