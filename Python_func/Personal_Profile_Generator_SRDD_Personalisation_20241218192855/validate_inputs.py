def validate_inputs(self, inputs):
        if not all(inputs):
            raise ValueError("All fields must be filled.")