def main():
    # Initialize the schedule
    schedule = Schedule()
    # Add some tasks to the schedule
    task1 = Task("Task 1", "Description 1", datetime.strptime("2023-12-01", "%Y-%m-%d"), "Pending")
    task2 = Task("Task 2", "Description 2", datetime.strptime("2023-12-05", "%Y-%m-%d"), "Pending")
    schedule.add_task(task1)
    schedule.add_task(task2)
    # Allocate time slots for tasks
    timeslot1 = TimeSlot(datetime.strptime("2023-11-30 09:00", "%Y-%m-%d %H:%M"), 
                         datetime.strptime("2023-11-30 11:00", "%Y-%m-%d %H:%M"), task1)
    timeslot2 = TimeSlot(datetime.strptime("2023-12-04 14:00", "%Y-%m-%d %H:%M"), 
                         datetime.strptime("2023-12-04 16:00", "%Y-%m-%d %H:%M"), task2)
    timeslot1.allocate_time()
    timeslot2.allocate_time()
    # Generate a productivity report
    report = Report(schedule)
    report.generate_report()