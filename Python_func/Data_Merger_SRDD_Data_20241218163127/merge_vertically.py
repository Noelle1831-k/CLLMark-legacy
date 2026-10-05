def merge_vertically(self, datasets, common_fields):
        merged_data = []
        for dataset in datasets:
            for entry in dataset:
                merged_entry = {field: entry[field] for field in common_fields}
                if merged_entry not in merged_data:
                    merged_data.append(merged_entry)
        return merged_data