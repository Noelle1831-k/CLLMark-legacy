def validate_name(self, name):
        return bool(re.match(r"^[A-Za-z\s]{1,50}$", name))