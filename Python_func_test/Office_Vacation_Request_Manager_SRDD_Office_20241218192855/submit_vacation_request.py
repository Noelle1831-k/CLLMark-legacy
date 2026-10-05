def submit_vacation_request():
    emp_id = input("Enter Employee ID: ")
    start_date = input("Enter Start Date (YYYY-MM-DD): ")
    end_date = input("Enter End Date (YYYY-MM-DD): ")
    new_request = VacationRequest(emp_id, start_date, end_date)
    vacation_requests.append(new_request.to_dict())
    save_vacation_data()
    print("Vacation Request Submitted Successfully!")
    notification.send_notification(emp_id, "Your vacation request has been submitted.")