def view_skills(self):
        '''
        Displays all skills in the character's skill list.
        '''
        if not self.skills:
            print("No skills found for this character.")
        for skill in self.skills.values():
            print(f"Skill: {skill.name}, Level: {skill.level}, Description: {skill.description}")