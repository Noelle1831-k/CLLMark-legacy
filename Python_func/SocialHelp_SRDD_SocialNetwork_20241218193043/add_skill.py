def add_skill(self, skill_name, description):
        skill = Skill(skill_name, description)
        self.skills.append(skill)