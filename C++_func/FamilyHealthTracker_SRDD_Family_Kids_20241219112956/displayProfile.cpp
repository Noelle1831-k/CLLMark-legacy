void FamilyMember::displayProfile() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Weight: " << weight << " kg\n";
    std::cout << "Height: " << height << " cm\n";
    std::cout << "Blood Pressure: " << systolicBP << "/" << diastolicBP << " mmHg\n";
}