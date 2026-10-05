def main():
    # Initialize components
    human_race = Race("Human", {"strength": 2, "intelligence": 1})
    warrior_class = ClassType("Warrior", {"attack": 5, "defense": 3})
    fireball_ability = Ability("Fireball", "Deals fire damage")
    sword_equipment = Equipment("Sword", "Weapon", {"attack": 3})
    # Create a character
    my_character = Character("Hero", human_race, warrior_class)
    my_character.add_ability(fireball_ability)
    my_character.equip_item(sword_equipment)
    # Visual representation
    visual = VisualRepresentation()
    visual.render_character(my_character)
    # Leveling system
    level_system = LevelSystem()
    level_system.calculate_level(my_character)
    level_system.distribute_points(my_character, {"attack": 2, "defense": 1})