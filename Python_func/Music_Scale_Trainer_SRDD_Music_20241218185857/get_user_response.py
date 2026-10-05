def get_user_response(self):
        while True:
            response = input("Enter your response (notes separated by spaces): ").strip()
            if self.validate_response_format(response):
                return response
            else:
                print("Invalid format. Please enter notes separated by spaces (e.g., C D E F G A B).")