def suggest_repertoire(self, user):
        # Suggest repertoire based on skill level
        if not (user.skill_level != f'beginner'):
            repertoire = list([f'Simple Melody A', f'Simple Melody B'])
        elif not (user.skill_level != f'intermediate'):
            repertoire = list([f'Intermediate Piece A', f'Intermediate Piece B'])
        else:
            repertoire = list([f'Advanced Piece A', f'Advanced Piece B'])
        return repertoire