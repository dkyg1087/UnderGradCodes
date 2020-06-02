package ntou.cs.java2020.hw1;

import java.security.SecureRandom;
import java.lang.Math; 
public class Complex{
    private double real;
    private double imaginary;
    SecureRandom randnum=new SecureRandom();//random number generator
    public Complex(double real,double imaginary){//constructor with args
        this.real=real;
        this.imaginary=imaginary;
    }
    public Complex(){//constructor without args
        this.real=randnum.nextDouble();
        this.imaginary=randnum.nextDouble();
    }
    public Complex getConjugate(){//getConjugate
        Complex temp=new Complex();
        temp.real=this.real;
        temp.imaginary=-1*this.imaginary;
        return temp;
    }
    public double getAbsolute(){//getAbsolute
        return Math.sqrt(this.real*this.real + this.imaginary*this.imaginary);
    }
    public Complex Add(Complex a){//complex addition
        Complex temp=new Complex(0.0,0.0);
        temp.real=this.real+a.real;
        temp.imaginary=this.imaginary+a.imaginary;
        return temp;
    }
    public Complex Subtract(Complex a){//complex subtraction
        Complex temp=new Complex(0.0,0.0);
        temp.real=this.real-a.real;
        temp.imaginary=this.imaginary-a.imaginary;
        return temp;
    }
    public Complex Multiply(Complex a){//complex multiplication
        Complex temp=new Complex(0.0,0.0);
        temp.real=(this.real*a.real)-(this.imaginary*a.imaginary);
        temp.imaginary=this.real*a.imaginary+(this.imaginary*a.real);
        return temp;        
    }
    public Complex Divide(Complex a){//complex division
        Complex temp=new Complex(0.0,0.0);
        temp.real=((this.real*a.real)+(this.imaginary*a.imaginary))/(a.real*a.real+a.imaginary*a.imaginary);
        temp.imaginary=((this.imaginary*a.real)-(this.real*a.imaginary))/(a.real*a.real+a.imaginary*a.imaginary);
        return temp;
    }
    public String toString(){//return with a+bi or a-bi
        if(this.imaginary>0) return String.format("%.2f", this.real)+"+"+ String.format("%.2f",this.imaginary)+"i";
        else return String.format("%.2f", this.real)+ String.format("%.2f",this.imaginary)+"i";
    }
}