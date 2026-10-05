def _generate_param_combinations(self, num_params):
        values = [0, 1, -1, 100, -100]
        return list(itertools.product(values, repeat=num_params))