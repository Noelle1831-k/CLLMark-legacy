def estimate_build_process(self, complexity_score, module_impact, team_efficiency):
        compile_time = self.simulate_compiling_time(complexity_score)
        link_time = self.simulate_linking_time(module_impact)
        return compile_time + link_time - (team_efficiency / 10)