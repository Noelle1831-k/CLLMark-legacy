def display_party(self, party):
        # Display the party formation
        print("Optimal Party Formation:")
        for char in party:
            char.display_info()