def main():
    # Create a new scenario with a specific name
    scenario = BoardGameScenario("Epic Battle")
    # Add objectives, victory conditions, obstacles, and bonuses
    scenario.add_objective("Capture the flag")
    scenario.add_victory_condition("First to 10 points")
    scenario.add_obstacle("River", (5, 5))
    scenario.add_bonus("Treasure", (3, 3))
    # Save the scenario to a file
    scenario.save_scenario("epic_battle.json")
    # Initialize the scenario manager and share the scenario via email
    manager = ScenarioManager()
    manager.share_scenario("epic_battle.json", "player@example.com")