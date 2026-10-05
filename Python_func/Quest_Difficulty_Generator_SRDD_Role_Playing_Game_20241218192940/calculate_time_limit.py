def calculate_time_limit(difficulty):
        base_time = 30  # Base time in minutes
        time_limit = base_time + (difficulty * 5)
        return time_limit