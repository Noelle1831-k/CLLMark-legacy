def __init__(self, username, email, profile_picture=None):
        self.username = username
        self.email = email
        self.profile_picture = profile_picture
        self.friends_list = []
        self.hunts_created = []
        self.hunts_participated = []