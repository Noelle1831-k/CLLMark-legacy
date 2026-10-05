def downgrade_skill(self, skill_name):
        '''
        Downgrades the level of a skill in the skill tree.
        '''
        if skill_name in self.skills:
            self.skills[skill_name].downgrade()
        else:
            print(f"Skill '{skill_name}' does not exist in the skill tree.")