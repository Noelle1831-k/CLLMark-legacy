def display_tree(self):
        '''
        Displays all skills in the skill tree along with their details.
        '''
        if not self.skills:
            print("The skill tree is empty.")
        for skill in self.skills.values():
            print(f"Skill: {skill.name}, Level: {skill.level}, Description: {skill.description}, Dependencies: {', '.join(skill.dependencies)}")