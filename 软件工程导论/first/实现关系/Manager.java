package สตั้4;

public class Manager extends Employee{
	protected double TripS;
	public Manager() {
		
	}

	public Manager(double B,double H,double M,double T) {
		super(B, H, M, T);
	}

	public void setSubsidy() {
		HouseS=0.2*BaseSalary;TrafficS=0.2*BaseSalary;MedicalS=1000;TripS=2000;
	}

	public double CalSalary() {
		return  BaseSalary+HouseS+MedicalS+TrafficS+TripS;
	}
	
}
