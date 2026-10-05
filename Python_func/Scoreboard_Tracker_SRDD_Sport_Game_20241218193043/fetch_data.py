def fetch_data(self):
        # Simulate fetching data from an external source
        games = ["Soccer", "Basketball", "Tennis"]
        return {game: (random.randint(0, 5), random.randint(0, 5)) for game in games}