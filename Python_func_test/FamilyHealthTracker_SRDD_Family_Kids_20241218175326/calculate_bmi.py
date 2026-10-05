def calculate_bmi(self, user_profile):
        user_id = user_profile.user_id
        weight = self.get_metric(user_profile, "weight")
        height = self.get_metric(user_profile, "height")
        if weight != "Metric not found" and height != "Metric not found":
            bmi = weight / ((height / 100) ** 2)
            print(f"BMI for {user_profile.name}: {bmi:.2f}")
        else:
            print("Insufficient data to calculate BMI.")