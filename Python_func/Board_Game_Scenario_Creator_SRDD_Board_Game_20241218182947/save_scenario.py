def save_scenario(self, scenario, filename):
        '''
        Save the scenario to a file.
        Parameters:
        scenario (BoardGameScenario): The scenario object to be saved.
        filename (str): The name of the file to save the scenario.
        '''
        scenario_data = {
            "name": scenario.name,
            "board_setup": scenario.board_setup.to_dict(),
            "objectives": [obj.to_dict() for obj in scenario.objectives],
            "victory_conditions": [vc.to_dict() for vc in scenario.victory_conditions],
            "obstacles": [obs.to_dict() for obs in scenario.obstacles],
            "bonuses": [bonus.to_dict() for bonus in scenario.bonuses]
        }
        with open(filename, 'w') as file:
            json.dump(scenario_data, file)
        print(f"Scenario saved successfully to {filename}")