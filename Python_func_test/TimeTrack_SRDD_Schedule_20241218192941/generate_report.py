def generate_report(self):
        if self.time_allocator:
            allocation = self.time_allocator.get_time_allocation()
            for activity, time in allocation.items():
                print(f"Activity: {activity}, Time: {time} minutes")
            self.visualize_time_allocation(allocation)
        else:
            print("Time allocator not set.")