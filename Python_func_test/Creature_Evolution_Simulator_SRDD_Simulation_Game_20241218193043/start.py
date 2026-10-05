def start(self):
        while True:
            self.simulation.run_cycle()
            self.simulation.display_population()
            self.environment.display_conditions()
            self.adjust_environment()