def create_complaint(self, complaint):
        self.complaints.append(complaint)
        assigned_agent_id = complaint.assigned_agent.agent_id if complaint.assigned_agent else "NULL"
        self.db.execute_query(
            f"INSERT INTO complaints (complaint_id, customer_id, description, status, priority, assigned_agent) "
            f"VALUES ({complaint.complaint_id}, {complaint.customer_id}, '{complaint.description}', "
            f"'{complaint.status}', '{complaint.priority}', {assigned_agent_id})"
        )