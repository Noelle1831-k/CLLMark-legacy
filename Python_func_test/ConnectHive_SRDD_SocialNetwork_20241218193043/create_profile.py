def create_profile(self):
        self.name = input("Enter your name: ")
        self.location = input("Enter your location: ")
        self.experience = input("Enter your beekeeping experience: ")
        self.interests = input("Enter your interests (comma-separated): ").split(',')
        print(f"Profile created for {self.name}.")