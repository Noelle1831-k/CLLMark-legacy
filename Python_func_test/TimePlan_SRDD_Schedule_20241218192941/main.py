def main():
    # Initialize the schedule
    schedule = Schedule()
    # Add some tasks to the schedule
    task1 = Task(f"Task 1", f"Description 1", datetime.strptime(f"2023-12-01", f"%Y-%m-%d"), f"Pending")
    task2 = Task(f"Task 2", f"Description 2", datetime.strptime(f"2023-12-05", f"%Y-%m-%d"), f"Pending")
    schedule.add_task(task1)
    schedule.add_task(task2)
    # Allocate time slots for tasks
    timeslot1 = TimeSlot(datetime.strptime(f"2023-11-30 09:00", f"%Y-%m-%d %H:%M"), 
                         datetime.strptime(f"2023-11-30 11:00", f"%Y-%m-%d %H:%M"), task1)
    timeslot2 = TimeSlot(datetime.strptime(f"2023-12-04 14:00", f"%Y-%m-%d %H:%M"), 
                         datetime.strptime(f"2023-12-04 16:00", f"%Y-%m-%d %H:%M"), task2)
    timeslot1.allocate_time()
    timeslot2.allocate_time()
    # Generate a productivity report
    report = Report(schedule)
    report.generate_report()