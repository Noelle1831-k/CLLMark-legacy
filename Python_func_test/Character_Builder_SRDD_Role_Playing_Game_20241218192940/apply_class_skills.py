def apply_class_skills(self, character):
        for skill, value in self.base_skills.items():
            if skill in character.attributes:
                character.attributes[skill] = character.attributes[skill] + value