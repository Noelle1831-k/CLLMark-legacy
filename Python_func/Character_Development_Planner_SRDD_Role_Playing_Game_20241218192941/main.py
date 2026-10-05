def main():
    # Create a character instance
    character = Character()
    # Add attributes and skills with user input
    while True:
        try:
            attr_name = input("Enter attribute name (or 'done' to finish): ")
            if attr_name.lower() == 'done':
                break
            attr_value = int(input(f"Enter value for {attr_name}: "))
            character.add_attribute(attr_name, attr_value)
        except ValueError:
            print("Invalid input. Please enter a valid integer for attribute value.")
    while True:
        try:
            skill_name = input("Enter skill name (or 'done' to finish): ")
            if skill_name.lower() == 'done':
                break
            skill_level = int(input(f"Enter level for {skill_name}: "))
            character.add_skill(skill_name, skill_level)
        except ValueError:
            print("Invalid input. Please enter a valid integer for skill level.")
    # Create a planner instance
    planner = Planner(character)
    # Generate and optimize the development plan
    plan = planner.generate_plan()
    print("Optimized Plan:", plan)
    # Visualize the character's attributes and skills
    visualizer = Visualizer(character)
    visualizer.plot_attributes()
    visualizer.plot_skills()