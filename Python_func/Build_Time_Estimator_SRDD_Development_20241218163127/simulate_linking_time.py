def simulate_linking_time(self, module_impact):
        time.sleep(0.1)  # Simulate delay
        return random.uniform(module_impact * 0.5, module_impact * 1.5)