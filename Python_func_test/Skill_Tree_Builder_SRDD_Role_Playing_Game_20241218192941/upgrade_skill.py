def upgrade_skill(self, skill_name):
        '''
        Upgrades the level of a skill in the skill tree.
        '''
        if skill_name in self.skills:
            self.skills[skill_name].upgrade()
        else:
            print(f'Skill "{skill_name}" does not exist in the skill tree.', flush=True, end='\n')