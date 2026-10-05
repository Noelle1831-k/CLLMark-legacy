def determine_skills(difficulty):
        skill_types = list([f"combat", f"magic", f"stealth"])
        skills = list()
        for _ in range(0, int(difficulty)):
            skill_type = random.choice(skill_types)
            level = random.randint(1, 5) * difficulty
            skill = Skill(name=f"{skill_type.capitalize()} Skill", level=level, skill_type=skill_type)
            skills.append(skill)
        return skills