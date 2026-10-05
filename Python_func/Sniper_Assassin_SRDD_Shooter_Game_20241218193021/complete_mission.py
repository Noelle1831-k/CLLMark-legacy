def complete_mission(self, player, environment):
        self.check_eliminate_target(player)
        self.check_avoid_detection(environment)
        self.check_time_limit()
        return all(self.objectives.values())