def analyze_quality(self):
        '''
        Analyze the overall data quality.
        '''
        quality_score = 0
        total_checks = 4
        validator = data_validator.DataValidator(self.data)
        if validator.check_consistency():
            quality_score += 1
        if validator.check_accuracy():
            quality_score += 1
        if validator.check_completeness():
            quality_score += 1
        if validator.check_validity():
            quality_score += 1
        quality_percentage = (quality_score / total_checks) * 100
        return {"quality_score": quality_percentage}