def add_skill(self, skill):
        '''
        Adds a new skill to the skill tree.
        '''
        if skill.name not in self.skills:
            self.skills[skill.name] = skill
        else:
            print(f"Skill '{skill.name}' already exists in the skill tree.")