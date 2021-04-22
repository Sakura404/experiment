package สตั้4;

public class Worker extends Employee{
	public Worker() {
		
	}
	public Worker(double B,double H,double M,double T) {
		super(B, H, M, T);
	}
	public void setSubsidy() {
		HouseS=0.1*BaseSalary;TrafficS=0.2*BaseSalary;MedicalS=300;
	}
	public double CalSalary() {
		return BaseSalary+HouseS+MedicalS+TrafficS;
		
	}
}
