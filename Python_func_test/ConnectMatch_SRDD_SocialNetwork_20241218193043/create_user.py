def create_user(self):
        name = input("Enter your name: ")
        skills = input("Enter your skills (comma-separated): ").split(",")
        expertise = input("Enter your expertise (comma-separated): ").split(",")
        interests = input("Enter your interests (comma-separated): ").split(",")
        user = UserProfile(name=name, skills=skills, expertise=expertise, interests=interests)
        self.db.add_user(user)
        print(f"User {name} created successfully with ID: {user.user_id}")