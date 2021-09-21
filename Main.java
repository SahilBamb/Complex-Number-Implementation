/*
 *
 *  Java version
 *
 */


/* Main.java */

public class Main {

    public static void main(String[] args) {

        Complex a = new Complex(1, 2);
        Complex b = new Complex(1, 3);

        double i = 5;

        System.out.println(a + " + " + b + " = " + a.add(b));
        System.out.println(a + " - " + b + " = " + a.sub(b));
        System.out.println(a + " * " + b + " = " + a.mul(b));
        System.out.println(a + " / " + b + " = " + a.div(b));
        System.out.println("------------------------------");
        System.out.println(b + " + " + a + " = " + b.add(a));
        System.out.println(b + " - " + a + " = " + b.sub(a));
        System.out.println(b + " * " + a + " = " + b.mul(a));
        System.out.println(b + " / " + a + " = " + b.div(a));
        System.out.println("------------------------------");
        System.out.println(a + " + " + i + " = " + a.add(i));
        System.out.println(a + " - " + i + " = " + a.sub(i));
        System.out.println(a + " * " + i + " = " + a.mul(i));
        System.out.println(a + " / " + i + " = " + a.div(i));
        System.out.println("------------------------------");
        System.out.println(i + " + " + a + " = " + a.radd(i));
        System.out.println(i + " - " + a + " = " + a.rsub(i));
        System.out.println(i + " * " + a + " = " + a.rmul(i));
        System.out.println(i + " / " + a + " = " + a.rdiv(i));

    }
}

/* Rational.java */

class Complex {

    public Complex() {

        this(0);
    }

    public Complex(double real) {

        this(real,0);
    }

    public Complex(double real, double img) {

        this.real = real;
        this.img = img;
    }

    public Complex add(Complex o) {

        return new Complex(real+o.real, img+o.img);
    }

    public Complex add(double n) {

        return new Complex(real+n,img);
    }

    public Complex radd(double n) {

        return this.add(n);

    }

    public Complex div(Complex o) {
        Complex top = new Complex(o.real, -o.img);
        top = this.mul(top);
        double denom = ((o.real*o.real) + (o.img*o.img));
        return top.div(denom);
    }

    public Complex div(double n) {

        return new Complex(real/n, img/n);
    }

    public Complex rdiv(double n) {

        return new Complex(n).div(this);

    }

    public Complex mul(Complex o) {

        return new Complex((real*o.real - img*o.img), ((real*o.img) + (o.real*img)));
    }

    public Complex mul(double n) {

        return new Complex(real*n, img*n);
    }

    public Complex rmul(double n) {

        return this.mul(n);

    }

    public Complex sub(Complex o) {

        return new Complex(real - o.real, img - o.img);
    }

    public Complex sub(double n) {

        return new Complex(real-n, img);
    }

    public Complex rsub(double n) {

        return new Complex(n-real, -img);

    }

    public String toString() {
        return (img>=0) ? "(" + real + " + " + img + "i)" : "(" + real + " - " + Math.abs(img) + "i)";
    }

    private double real;
    private double img;
}