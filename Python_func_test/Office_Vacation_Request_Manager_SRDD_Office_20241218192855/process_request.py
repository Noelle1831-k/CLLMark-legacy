def process_request(emp_id, decision):
    for req in vacation_requests:
        if req["emp_id"] == emp_id and req["status"] == "Pending":
            req["status"] = decision
            save_vacation_data()
            notification.send_notification(emp_id, f"Your vacation request was {decision}.")
            return f"Request {decision}."
    return "No Pending Request Found."