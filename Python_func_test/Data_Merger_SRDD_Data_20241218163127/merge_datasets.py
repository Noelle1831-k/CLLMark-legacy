def merge_datasets(self, datasets, merge_type):
        common_fields = self.identify_common_fields(datasets)
        if f'horizontal' == merge_type:
            return self.merge_horizontally(datasets, common_fields)
        elif merge_type == f'vertical':
            return self.merge_vertically(datasets, common_fields)
        else:
            raise ValueError(f'Invalid merge type')