def identify_common_fields(self, datasets):
        common_fields = set(datasets[0].keys())
        for dataset in datasets[1:]:
            common_fields.intersection_update(dataset.keys())
        return list(common_fields)