package 实验3;

public class Student extends Person {
	public Student(long n,String s, char c, int i) {
		super(s, c, i);
		number=n;
		// TODO 自动生成的构造函数存根
	}
	public void setfraction(double a,double b,double c) {
		phi=a;comp=b;eng=c;
	}
	long number;
	double phi;
	double comp;
	double eng;
	public double max() {
		return phi>comp?phi>eng?phi:eng:comp>eng?comp:eng;
	}
	public String toString() {
		return number +"\t"+ name+"\t"+sex+"\t"+age+"\t"+max();
	}
}
