int main() {
    FestivalManager *manager = createFestivalManager();
    createFestival(manager);
    manageTicketSales(manager);
    handleLogistics(manager);
    simulateChallenges(manager);
    freeFestivalManager(manager);
    return 0;
}