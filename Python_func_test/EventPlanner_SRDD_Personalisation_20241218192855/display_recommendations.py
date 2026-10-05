def display_recommendations(self, recommendations):
        print("Here are your personalized vendor recommendations:")
        for vendor in recommendations:
            print(f"Vendor: {vendor.name}, Service: {vendor.service}, Rating: {vendor.rating}, Special Features: {vendor.special_features}")