def select_character():
        characters = ["Warrior", "Mage", "Archer"]
        name = random.choice(characters)
        return Character(name)