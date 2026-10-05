def __init__(self, username, profile, subjects, expertise, availability):
        super().__init__(username, profile, subjects)
        self.expertise = expertise
        self.availability = availability