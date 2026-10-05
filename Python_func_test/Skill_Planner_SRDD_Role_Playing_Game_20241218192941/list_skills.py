def list_skills(self):
        print("Available Skills:")
        for skill_name, skill in self.available_skills.items():
            print(f"  {skill_name}: Max Level {skill.max_level}")