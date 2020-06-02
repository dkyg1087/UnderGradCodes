package ntou.cs.java2020.ex3;
public class InterfaceTest {
	public static void main(String args[]) {
		E e = new E();
		A a = e;
		a.methodA();
		B b = e;
		b.methodB();
		C c = e;
		c.methodC1();
		c.methodC2();
	}
}

interface A {
	void methodA();
}

interface B {
	void methodB();
}

abstract class C {
	public abstract void methodC1();

	public void methodC2() {
		System.out.println("C2 of C");
	}
}

abstract class D extends C {
	@Override
	public void methodC2() {
		System.out.println("C2 of D");
	}
}

class E extends D implements A,B {
	public void methodA(){
		System.out.println("A of E");
	}
	public void methodB() {
		System.out.println("B of E");
	}
	public void methodC1(){
		System.out.println("C1 of E");
	}
	
}