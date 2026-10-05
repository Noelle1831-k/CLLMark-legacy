def validate_email(self, email):
        return bool(re.match(r"^[\w\.-]+@[\w\.-]+\.\w+$", email))