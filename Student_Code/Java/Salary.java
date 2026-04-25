import java.io.*;
import java.util.*;

public class Salary{
    public static void main(String[] args) throws IOException{
        //Code to find the text file in the parent directory
        String path = Salary.class.getProtectionDomain().getCodeSource().getLocation().getPath(); 
        File base_dir = new File(path).getParentFile().getParentFile().getParentFile();
        File txt_file = new File(base_dir, "employees.txt");

        BufferedReader reader = new BufferedReader(new FileReader(txt_file));

    }

    static Employee fromString(String emp){
        
    }
}

abstract class Employee {
    
}

class PartTime extends Employee{
    
}


class FullTime extends Employee{
    
}