def get_targets(self, level_number):
        num_targets = level_number * 5
        return [target.Target("moving" if i % 2 == 0 else "static") for i in range(num_targets)]