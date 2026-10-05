def merge_datasets(self, datasets, merge_type):
        common_fields = self.identify_common_fields(datasets)
        if merge_type == 'horizontal':
            return self.merge_horizontally(datasets, common_fields)
        elif merge_type == 'vertical':
            return self.merge_vertically(datasets, common_fields)
        else:
            raise ValueError("Invalid merge type")