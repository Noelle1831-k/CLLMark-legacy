def add_skill(self, skill_name, skill_level):
        if skill_name not in self.skills:
            self.skills[skill_name] = skill_level
        else:
            self.skills[skill_name] += skill_level