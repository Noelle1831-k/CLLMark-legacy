def display_tracking_info(self, tracking_data):
        print("Real-Time Tracking Information:")
        for data_point in tracking_data:
            print(f"Time: {data_point['timestamp']}, Activity: {data_point['activity']}")