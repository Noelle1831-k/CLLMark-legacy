def display_party_info(self):
        # Display detailed party information
        print("Party Members:")
        for member in self.members:
            member.display_character_info()
        print(f"Synergy Score: {self.synergy_score}")