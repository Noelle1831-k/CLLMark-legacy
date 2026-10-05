def initialize_sample_characters():
    # Initialize characters with sample data
    char1 = Character("Archer", "Ranger", {"strength": 5, "agility": 8}, ["shoot", "dodge"], ["stealth"])
    char2 = Character("Warrior", "Fighter", {"strength": 9, "agility": 4}, ["slash", "block"], ["rage"])
    char3 = Character("Mage", "Sorcerer", {"strength": 3, "agility": 5}, ["fireball", "teleport"], ["arcane shield"])
    return [char1, char2, char3]