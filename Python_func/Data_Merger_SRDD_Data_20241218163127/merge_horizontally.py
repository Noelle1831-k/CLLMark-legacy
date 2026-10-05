def merge_horizontally(self, datasets, common_fields):
        merged_data = []
        for dataset in datasets:
            for entry in dataset:
                merged_entry = {field: entry[field] for field in common_fields}
                merged_data.append(merged_entry)
        return merged_data