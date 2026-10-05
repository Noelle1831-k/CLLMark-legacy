def view_requests():
    print("\nPending Vacation Requests:")
    for req in vacation.vacation_requests:
        if req["status"] == "Pending":
            print(req)