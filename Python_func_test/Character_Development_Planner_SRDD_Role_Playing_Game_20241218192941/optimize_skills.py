def optimize_skills(self, skills):
        sorted_skills = sort_skills(skills)
        return {k: v + 1 for k, v in sorted_skills.items()}