def recommend_technique(self, user):
        import random
        technique = random.choice(self.techniques)
        print(f"Recommended relaxation technique for {user.name}: {technique}")