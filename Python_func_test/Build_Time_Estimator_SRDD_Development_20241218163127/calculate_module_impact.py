def calculate_module_impact(self, module_count):
        # Deterministic calculation based on module count
        base_dependency_factor = 1.5
        additional_factor = (module_count / 10) * 0.1  # Increase factor slightly with more modules
        dependency_factor = base_dependency_factor + additional_factor
        return module_count * dependency_factor