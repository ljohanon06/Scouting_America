from math import floor
from pathlib import Path

def get_single_age(line):
    """Take an employee line and returns the age"""
    tokens = line.split(" | ")  #Splits the string into a list of strings
    age_token = tokens[4]       #The 5th (index 4) part holds the average age
    return int(age_token)       #Convert from a string to an age

def main():
    BASE_DIR = Path(__file__).resolve().parent.parent.parent #Code to place employees.txt in top folder
    txt_file = BASE_DIR / "employees.txt"

    with open(txt_file) as file:    #Opens the file in the variable file, will close it after the 'with' statement is over
        lines = file.readlines()    #Returns a list of every line in the file
    age_sum = 0
    for line in lines:
        age_sum += get_single_age(line) #Sum the age of every line
    average_age = age_sum/len(lines)    
    years = floor(average_age)          
    months = floor((average_age-years)*12)  #Takes the decimal part of the average age and turns it into months, Eg 33.5 -> 6 months
    print(f"The average age of the employees is {years} years and {months} months")


if __name__ == "__main__":
    main()

"""
Text File:
Stacia Fisher | Full | 84131 | Male | 30
Carlye Best | Part | 16-47 | Male | 23
Roslyn Rich | Full | 52966 | Female | 27
Lotte Webster | Full | 54237 | Male | 27
Zitella Shelton | Part | 16-14 | Male | 35
Nerty Kent | Part | 29-22 | Male | 52
"""