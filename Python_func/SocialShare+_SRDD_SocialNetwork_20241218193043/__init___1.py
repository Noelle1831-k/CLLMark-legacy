def __init__(self, username):
        self.username = username
        self.profile = Profile(username)
        self.content_list = []
        self.saved_content = []
        self.projects = []