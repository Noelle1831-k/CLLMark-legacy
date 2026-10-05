def validate_response_format(self, response):
        # Basic validation to ensure response contains only letters and spaces
        return all(char.isalpha() or char.isspace() for char in response)