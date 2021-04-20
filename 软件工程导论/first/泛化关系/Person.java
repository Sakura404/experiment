package 实验3;

public class Person {
	String name;
	int age; 
	char sex;
	public Person(String s){   /*设置姓名*/
		this.name=s;
	}
	public Person(String s,char c) {/*调用本类的构造函数Person(String s)，设置性别*/
		this.name=s;
		this.sex=c;
	}
	public Person(String s,char c,int i) { /*调用本类的构造函数PersonPerson(String s,char)设置年龄*/
		this.name=s;
		this.sex=c;
		this.age=i;
	}
	@Override
	public String toString() {
		return  name+' '+sex+' '+age;//Integer.toString(age);
	}
}

