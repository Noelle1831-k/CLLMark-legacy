def remove_skill(self, skill_name):
        '''
        Removes a skill from the skill tree by its name.
        '''
        if skill_name in self.skills:
            del self.skills[skill_name]
        else:
            print(f"Skill '{skill_name}' does not exist in the skill tree.")