def assign_complaint(self, complaint, agent):
        complaint.assign_agent(agent)
        self.db.execute_query(
            f"UPDATE complaints SET assigned_agent={agent.agent_id} WHERE complaint_id={complaint.complaint_id}"
        )