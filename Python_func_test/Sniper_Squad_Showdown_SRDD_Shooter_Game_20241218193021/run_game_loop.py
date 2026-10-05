def run_game_loop(self):
        for mission in self.missions:
            self.current_mission = mission
            mission.generate_mission()
            strategy.plan_mission(self.players, mission)
            strategy.execute_strategy(self.players, mission)
            mission.complete_mission()
            self.provide_feedback()