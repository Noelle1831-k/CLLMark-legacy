def validate_inputs(self, inputs):
        if not all(inputs):
            raise ValueError(f'All fields must be filled.')