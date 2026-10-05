def validate(self):
        '''
        Executes all validation checks on the dataset and stores the results in the validation report.
        '''
        mv_validator = MissingValuesValidator(self.dataset)
        mv_results = mv_validator.check_missing_values()
        self.report.add_entry(mv_results)
        dv_validator = DuplicateValuesValidator(self.dataset)
        dv_results = dv_validator.check_duplicates()
        self.report.add_entry(dv_results)
        ov_validator = OutliersValidator(self.dataset)
        ov_results = ov_validator.check_outliers()
        self.report.add_entry(ov_results)
        dt_validator = DataTypeValidator(self.dataset)
        dt_results = dt_validator.check_data_types()
        self.report.add_entry(dt_results)