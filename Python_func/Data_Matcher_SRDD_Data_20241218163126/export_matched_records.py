def export_matched_records(self, output_file):
        if not self.matched_records:
            print("No matched records to export.")
            return
        with open(output_file, 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            # Extract headers from the first record pair
            if self.matched_records:
                headers = list(self.matched_records[0][0].data.keys()) + list(self.matched_records[0][1].data.keys())
                writer.writerow(headers)
            # Write each matched record pair to the CSV
            for record1, record2 in self.matched_records:
                writer.writerow(
                    list(record1.data.values()) + list(record2.data.values())
                )