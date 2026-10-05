def match_data(self):
        matched_records = []
        records1 = self.dataset1.get_records()
        records2 = self.dataset2.get_records()
        for record1 in records1:
            for record2 in records2:
                if all(record1.get_field_value(field) == record2.get_field_value(field) for field in self.fields_to_match):
                    matched_records.append((record1, record2))
        self.matched_records = matched_records