def __init__(self):
        self.length = 5000  # Total length of the track in meters
        self.width = 20     # Width of the track in meters
        self.obstacles = [] # List to store obstacles on the track
        self.generate_track()