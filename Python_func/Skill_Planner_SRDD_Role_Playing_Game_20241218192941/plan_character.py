def plan_character(self):
        name = input("Enter character name: ")
        character = self.create_character(name)
        self.list_skills()
        while True:
            action = input("Enter 'add' to add skill, 'remove' to remove skill, 'done' to finish: ").lower()
            if action == 'done':
                break
            elif action == 'add':
                skill_name = input("Enter skill to add: ")
                if skill_name in self.available_skills:
                    level = validate_input("Enter skill level: ", int)
                    character.add_skill(skill_name, level)
                else:
                    print("Invalid skill name.")
            elif action == 'remove':
                skill_name = input("Enter skill to remove: ")
                character.remove_skill(skill_name)
            else:
                print("Invalid action.")
        character.display_character()
        save_character(character)