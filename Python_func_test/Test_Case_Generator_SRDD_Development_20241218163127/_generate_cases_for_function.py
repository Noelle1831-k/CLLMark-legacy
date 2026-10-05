def _generate_cases_for_function(self, func):
        cases = []
        param_names = [arg.arg for arg in func.args.args]
        param_combinations = self._generate_param_combinations(len(param_names))
        for combination in param_combinations:
            case = {name: value for name, value in zip(param_names, combination)}
            cases.append(case)
        edge_cases = generate_edge_cases(param_names)
        cases.extend(edge_cases)
        return cases