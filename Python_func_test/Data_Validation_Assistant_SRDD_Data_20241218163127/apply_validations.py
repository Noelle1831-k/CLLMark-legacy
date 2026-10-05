def apply_validations(self, data, validation_rules):
        results = {}
        results['data_type'] = self.validate_data_type(data, validation_rules.get('data_type', {}))
        results['range'] = self.validate_range(data, validation_rules.get('range', {}))
        results['uniqueness'] = self.validate_uniqueness(data, validation_rules.get('uniqueness', []))
        return results