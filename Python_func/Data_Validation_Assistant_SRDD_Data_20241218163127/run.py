def run(self, file_path, validation_rules):
        data = self.data_importer.import_data(file_path)
        validation_results = self.validator.apply_validations(data, validation_rules)
        self.report.generate_report(validation_results)