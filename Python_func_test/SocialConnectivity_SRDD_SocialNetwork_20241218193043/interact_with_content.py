def interact_with_content(self, user, interaction_type):
        if not user or not interaction_type:
            raise ValueError("User and interaction type must be provided.")
        self.interactions.append((user, interaction_type))