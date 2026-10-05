def remove_skill(self, skill_name):
        if skill_name in self.skills:
            del self.skills[skill_name]