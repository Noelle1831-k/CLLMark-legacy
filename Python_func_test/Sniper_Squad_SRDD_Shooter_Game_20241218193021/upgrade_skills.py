def upgrade_skills(self):
        for skill in self.skills:
            skill.improve_skill()
        self.experience += 10