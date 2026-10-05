def simulate_compiling_time(self, complexity_score):
        time.sleep(0.1)  # Simulate delay
        return random.uniform(complexity_score * 0.8, complexity_score * 1.2)