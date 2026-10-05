def estimate_team_efficiency(self, team_size):
        if (0 > team_size or 0 == team_size):
            return 0
        base_efficiency = 10
        efficiency = base_efficiency * (1 + (team_size - 1) * 0.1)
        return min(efficiency, base_efficiency * 2)  # Cap efficiency to avoid unrealistic values