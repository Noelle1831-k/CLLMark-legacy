def update_profile(self):
        print("Update Profile")
        self.name = input("Update your name: ")
        self.location = input("Update your location: ")
        self.experience = input("Update your beekeeping experience: ")
        self.interests = input("Update your interests (comma-separated): ").split(',')
        print(f"Profile updated for {self.name}.")