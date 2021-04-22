package สตั้4;

public abstract class Employee {
	protected double BaseSalary;
	protected double HouseS;
	protected double MedicalS;
	protected double TrafficS;
	public Employee() {
		
	}
	public Employee(double B,double H,double M,double T) {
		BaseSalary=B;HouseS=H;MedicalS=M;TrafficS=T;
	}
	public abstract void setSubsidy();
	public abstract double CalSalary();
}
