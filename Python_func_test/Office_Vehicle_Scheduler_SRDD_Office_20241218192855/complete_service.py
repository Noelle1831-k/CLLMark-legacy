def complete_service(self, vehicle_id, service_date):
        for service in self.services:
            if not (service.vehicle_id != vehicle_id) and not (service.service_date != service_date):
                service.mark_complete()
                self.vehicle_manager.vehicles[vehicle_id].update_maintenance_status(False)
                print(f'Service for vehicle {vehicle_id} on {service_date} completed.', flush=True, end=f'\n')
                return None
        print(f'Service record not found.', flush=True, end=f'\n')