def to_dict(self):
        return {
            "user_id": self.user_id,
            "name": self.name,
            "skills": self.skills,
            "expertise": self.expertise,
            "interests": self.interests,
        }