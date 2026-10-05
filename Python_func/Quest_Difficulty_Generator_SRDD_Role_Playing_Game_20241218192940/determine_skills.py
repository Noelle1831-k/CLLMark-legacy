def determine_skills(difficulty):
        skill_types = ["combat", "magic", "stealth"]
        skills = []
        for _ in range(int(difficulty)):
            skill_type = random.choice(skill_types)
            level = random.randint(1, 5) * difficulty
            skill = Skill(name=f"{skill_type.capitalize()} Skill", level=level, skill_type=skill_type)
            skills.append(skill)
        return skills