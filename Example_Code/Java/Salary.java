import java.io.*;
import java.util.*;

public class Salary{
    public static void main(String[] args) throws IOException{
        BufferedReader reader = new BufferedReader(new FileReader("employees.txt"));

        ArrayList<Employee> employees = new ArrayList<>();

        String line = reader.readLine();
        
        while(line != null){
            employees.add(fromString(line));
            line = reader.readLine();
        }

        //Combined
        long sum = 0;
        int count = 0;
        for(Employee e : employees){
            sum += e.getSalary();
            count++;
        }

        System.out.printf("Combined: %.2f\n", (double)sum/count);

        //Part Full
        long partSum = 0;
        int partCount = 0;
        long fullSum = 0;
        int fullCount = 0;
        for(Employee e : employees){
            if(e instanceof PartTime){
                partSum += e.getSalary();
                partCount++;
            }else{
                fullSum += e.getSalary();
                fullCount++;
            }
        }

        System.out.printf("Part: %.2f\n", (double)partSum/partCount);
        System.out.printf("Full: %.2f\n", (double)fullSum/fullCount);
        
    }

    public static Employee fromString(String emp){
        String[] words = emp.split("\\|");
        if(words[1].trim().equals("Full")){
            int age = Integer.parseInt(words[4].trim());
            int salary = Integer.parseInt(words[2].trim());
            boolean gender = words[3].trim().equals("Male");

            return new FullTime(words[0].trim(),gender,age,salary);
        }else{
            int age = Integer.parseInt(words[4].trim());
            String salaryParts[] = words[2].trim().split("-");
            int hours = Integer.parseInt(salaryParts[0]);
            int wage = Integer.parseInt(salaryParts[1]);
            boolean gender = words[3].trim().equals("Male");

            return new PartTime(words[0].trim(),gender,age,hours,wage);
        }
    }
}

abstract class Employee {
    public String name;
    public boolean gender; //True = Male
    public int age;

    public Employee(String name, boolean gender, int age){
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    abstract public int getSalary();
}

class PartTime extends Employee{
    public int hours;
    public int hourlyWage;

    public PartTime(String name, boolean gender, int age, int hours, int hourlyWage){
        super(name,gender,age);
        this.hours = hours;
        this.hourlyWage = hourlyWage;
    }

    @Override
    public int getSalary(){
        return 52*hours*hourlyWage;
    }
}


class FullTime extends Employee{
    public int salary;

    public FullTime(String name, boolean gender, int age, int salary){
        super(name,gender,age);
        this.salary = salary;
    }

    @Override
    public int getSalary(){
        return salary;
    }
}