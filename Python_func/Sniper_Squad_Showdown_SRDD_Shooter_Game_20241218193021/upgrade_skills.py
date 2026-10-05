def upgrade_skills(self):
        print(f"{self.name} is upgrading skills...")
        for skill in self.skills:
            upgrade_choice = input(f"Upgrade {skill}? (yes/no): ")
            if upgrade_choice.lower() == 'yes':
                self.skills[skill] += 1
                print(f"{skill} upgraded to {self.skills[skill]}")
            else:
                print(f"{skill} remains at {self.skills[skill]}")