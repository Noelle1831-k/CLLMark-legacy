def main():
    # Initialize the Complaint Management System
    cms = ComplaintManagementSystem()
    # Adding customers to the system
    customer1 = Customer(1, "John Doe", "john@example.com")
    customer2 = Customer(2, "Jane Smith", "jane@example.com")
    cms.add_customer(customer1)
    cms.add_customer(customer2)
    # Adding support agents to the system
    agent1 = SupportAgent(1, "Agent A", "agentA@example.com")
    agent2 = SupportAgent(2, "Agent B", "agentB@example.com")
    cms.add_agent(agent1)
    cms.add_agent(agent2)
    # Customers submitting complaints
    complaint1 = customer1.submit_complaint("Issue with product X")
    complaint2 = customer2.submit_complaint("Issue with service Y")
    cms.create_complaint(complaint1)
    cms.create_complaint(complaint2)
    # Assigning complaints to agents
    cms.assign_complaint(complaint1, agent1)
    cms.assign_complaint(complaint2, agent2)
    # Tracking the status of complaints
    cms.track_complaint(complaint1.complaint_id)
    cms.track_complaint(complaint2.complaint_id)
    # Generating a comprehensive report of all complaints
    cms.generate_report()