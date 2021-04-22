package 实验4;
import java.util.*;
public class TestEmp {
	public static void main(String[] args) {
	System.out.println("请输入员工类型：（普通员工1经理2）");
	int input = new Scanner(System.in).nextInt();
	System.out.println("-------------------------------------------------");
	if(input!=1&&input!=2)
		System.out.println("输入有误");
	else if(input==1) 
	{
		Worker w =new Worker(5000,0,0,0);
		w.setSubsidy();
		System.out.println("员工编号：19551119067\t\t员工姓名：xxx（员工）");
		System.out.println("该员工的工资是:"+w.CalSalary());
	}	
	else
	{
		Manager m=new Manager(10000,0,0,0);
		m.setSubsidy();
		System.out.println("员工编号：19551119067\t\t员工姓名：xxx（经理）");
		System.out.println("该员工的工资是:"+m.CalSalary());
	}
	}
}
