import java.util.*;
public class basic1{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("eneter your name:");
        String name = sc.nextLine();
        System.out.println("enter your rollno :");
        int roll = sc.nextInt();
        System.out.println("hello " + name + " your rollno is " + roll);

        sc.close();
    }
}