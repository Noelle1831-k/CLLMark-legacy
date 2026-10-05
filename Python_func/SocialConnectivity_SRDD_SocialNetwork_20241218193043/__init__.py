def __init__(self, username, interests):
        if not username or not isinstance(interests, list):
            raise ValueError("Invalid input: Username must be a string, and interests must be a list.")
        self.username = username
        self.interests = interests
        self.profile = {}