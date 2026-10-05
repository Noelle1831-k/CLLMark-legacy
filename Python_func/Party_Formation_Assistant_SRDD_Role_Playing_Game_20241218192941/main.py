def main():
    # Initialize characters with detailed attributes
    char1 = Character("Archer", "Ranger", {"attack": 8, "defense": 5, "agility": 9}, "High agility", "Low defense")
    char2 = Character("Mage", "Wizard", {"attack": 9, "defense": 3, "magic": 10}, "High magic", "Low health")
    char3 = Character("Warrior", "Fighter", {"attack": 7, "defense": 8, "strength": 9}, "High strength", "Low speed")
    char4 = Character("Healer", "Cleric", {"attack": 4, "defense": 6, "healing": 10}, "High healing", "Low attack")
    # Initialize party
    party = Party()
    party.add_member(char1)
    party.add_member(char2)
    party.add_member(char3)
    party.add_member(char4)
    # Optimize party
    optimizer = PartyOptimizer()
    optimizer.analyze_characters([char1, char2, char3, char4])
    suggested_party = optimizer.suggest_party([char1, char2, char3, char4])
    print("Suggested Party Composition:")
    for member in suggested_party.members:
        print(f"{member.name} - {member.class_type}")