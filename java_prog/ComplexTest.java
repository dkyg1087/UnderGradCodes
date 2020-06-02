package ntou.cs.java2020.hw1;

public class ComplexTest{//pretty self-explanatory, don't really know what to say here.
    public static void main(String[] args){
        Complex a = new Complex(1.10,2.20);
        Complex b = new Complex(3.30,-4.40);
        System.out.printf("Conjugates of a = %s\n",a.getConjugate().toString());
        System.out.printf("Absolute value of a = %.2f\n",a.getAbsolute());
        System.out.printf("Conjugates of b = %s\n",b.getConjugate().toString());
        System.out.printf("Absolute value of b = %.2f\n",b.getAbsolute());
        System.out.printf("a + b = %s\n",a.Add(b).toString());
        System.out.printf("a - b = %s\n",a.Subtract(b).toString());
        System.out.printf("a * b = %s\n",a.Multiply(b).toString());
        System.out.printf("a / b = %s\n",a.Divide(b).toString());
        Complex c = new Complex();
        Complex d = new Complex();
        System.out.printf("Conjugates of c = %s\n",c.getConjugate().toString());
        System.out.printf("Absolute value of c = %.2f\n",c.getAbsolute());
        System.out.printf("Conjugates of d = %s\n",d.getConjugate().toString());
        System.out.printf("Absolute value of d = %.2f\n",d.getAbsolute());
        System.out.printf("c + d = %s\n",c.Add(d).toString());
        System.out.printf("c - d = %s\n",c.Subtract(d).toString());
        System.out.printf("c * d = %s\n",c.Multiply(d).toString());
        System.out.printf("c / d = %s\n",c.Divide(d).toString());
    }
}