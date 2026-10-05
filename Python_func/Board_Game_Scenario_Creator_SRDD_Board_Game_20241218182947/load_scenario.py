def load_scenario(self, filename):
        '''
        Load a scenario from a file.
        Parameters:
        filename (str): The name of the file to be loaded.
        Returns:
        BoardGameScenario: The loaded scenario object.
        '''
        with open(filename, 'r') as file:
            scenario_data = json.load(file)
        scenario = BoardGameScenario(scenario_data["name"])
        scenario.board_setup = BoardSetup.from_dict(scenario_data["board_setup"])
        scenario.objectives = [Objective.from_dict(obj) for obj in scenario_data["objectives"]]
        scenario.victory_conditions = [VictoryCondition.from_dict(vc) for vc in scenario_data["victory_conditions"]]
        scenario.obstacles = [Obstacle.from_dict(obs) for obs in scenario_data["obstacles"]]
        scenario.bonuses = [Bonus.from_dict(bonus) for bonus in scenario_data["bonuses"]]
        print(f"Scenario loaded successfully from {filename}")
        return scenario