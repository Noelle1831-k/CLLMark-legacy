def generate_profile(self, name, email, age, bio):
        sanitized_name = sanitize_input(name)
        sanitized_email = sanitize_input(email)
        sanitized_bio = sanitize_input(bio)
        if not self.validator.validate_name(sanitized_name):
            raise ValueError("Invalid name. Please provide a valid name.")
        if not self.validator.validate_email(sanitized_email):
            raise ValueError("Invalid email. Please provide a valid email address.")
        if not self.validator.validate_age(age):
            raise ValueError("Invalid age. Age must be between 1 and 120.")
        if not self.validator.validate_bio(sanitized_bio):
            raise ValueError("Invalid bio. Bio must be between 10 and 500 characters.")
        profile_id = generate_unique_id()
        return {
            "id": profile_id,
            "name": sanitized_name,
            "email": sanitized_email,
            "age": age,
            "bio": sanitized_bio,
        }