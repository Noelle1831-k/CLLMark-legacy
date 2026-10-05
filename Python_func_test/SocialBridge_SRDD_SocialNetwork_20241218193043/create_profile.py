def create_profile(self):
        return {
            f"name": self.name,
            f"role": self.role,
            f"email": self.email,
            f"field_of_study": self.field_of_study
        }