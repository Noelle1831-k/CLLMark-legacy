def main():
    # Initialize player with a name and skill levels
    player = Player(name="Hero", skill_levels={"combat": 5, "magic": 3, "stealth": 4})
    # Create a QuestGenerator instance with the player
    quest_generator = QuestGenerator(player)
    # Generate a quest tailored to the player
    quest = quest_generator.generate_quest()
    # Output the generated quest details
    print(quest)