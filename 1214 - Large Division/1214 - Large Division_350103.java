import java.io.*;
import java.util.*;
import java.math.*;
 
class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int ca=0;
        for(int i=0; i<t; i++){
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            if(a.signum() !=1 ){
                a = a.multiply(BigInteger.valueOf(-1));
            }
            if(b.signum() !=1 ){
                b = b.multiply(BigInteger.valueOf(-1));
            }
            if(!a.mod(b).equals(BigInteger.valueOf(0))){
                System.out.println("Case "+ ++ca +": not divisible");
            }
            else {
                System.out.println("Case "+ ++ca +": divisible");
            }
        }
    }
}
 
