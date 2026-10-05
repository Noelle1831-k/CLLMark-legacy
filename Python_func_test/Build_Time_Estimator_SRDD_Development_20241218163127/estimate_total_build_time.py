def estimate_total_build_time(self):
        complexity_score = self.code_analyzer.analyze_code(self.source_files)
        module_impact = self.module_handler.calculate_module_impact(self.module_count)
        team_efficiency = self.team_calculator.estimate_team_efficiency(self.team_size)
        build_process_time = self.simulator.estimate_build_process(complexity_score, module_impact, team_efficiency)
        total_time = complexity_score + module_impact - team_efficiency + build_process_time
        return max(0, total_time)  # Ensure time is non-negative