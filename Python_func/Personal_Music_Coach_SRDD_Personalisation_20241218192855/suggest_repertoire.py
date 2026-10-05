def suggest_repertoire(self, user):
        # Suggest repertoire based on skill level
        if user.skill_level == "beginner":
            repertoire = ["Simple Melody A", "Simple Melody B"]
        elif user.skill_level == "intermediate":
            repertoire = ["Intermediate Piece A", "Intermediate Piece B"]
        else:
            repertoire = ["Advanced Piece A", "Advanced Piece B"]
        return repertoire