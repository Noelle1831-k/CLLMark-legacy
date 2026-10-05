def update_profile(self, name=None, age=None, gender=None, contact_info=None, emergency_contact=None):
        if name:
            self.name = name
        if age:
            self.age = age
        if gender:
            self.gender = gender
        if contact_info:
            self.contact_info = contact_info
        if emergency_contact:
            self.emergency_contact = emergency_contact