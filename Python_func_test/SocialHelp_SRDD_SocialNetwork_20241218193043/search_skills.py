def search_skills(self, skill_name, users):
        return [user for user in users if any(skill.name == skill_name for skill in user.skills)]