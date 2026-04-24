# /// script
# dependencies = [
#   "scipy",
# ]
# ///

from scipy.stats import gamma, pareto, bernoulli, randint
import sys
from pathlib import Path

def get_file_lines(file_name):
    with open(file_name, "r") as file:
        return file.readlines()
    
def get_name(names):
    index = randint.rvs(0,len(names))
    return names[index].strip()

def get_age():
    return 18 + int(gamma.rvs(3,scale=5))

def get_full_wage():
    return int(pareto.rvs(2.3596, scale=40000))

def get_part_wage():
    return int(pareto.rvs(1.5306, scale=10))

def get_part_hours():
    return randint.rvs(15,35)

def get_gender():
    return "Male" if bernoulli.rvs(0.6) == 1 else "Female"

def get_wage():
    if bernoulli.rvs(0.5) == 0:
        hours = get_part_hours()
        wage = get_part_wage()
        return (f"Part | {hours}-{wage}")
    else:
        full = get_full_wage()
        return (f"Full | {full}")
    
def get_employee_data(first_names, last_names):
    first = get_name(first_names)
    last = get_name(last_names)
    age = get_age()
    wage = get_wage()
    gender = get_gender()

    return (f"{first} {last} | {wage} | {gender} | {age}")

def output_file(lines):
    BASE_DIR = Path(__file__).resolve().parent.parent.parent

    txt_first = BASE_DIR / "Example_Code" / "Generate_Employees" / "first-names.txt"
    txt_last = BASE_DIR / "Example_Code" / "Generate_Employees" / "last-names.txt"
    txt_file = BASE_DIR / "employees.txt"

    first_names = get_file_lines(txt_first)
    last_names = get_file_lines(txt_last)

    last_names = list(map(lambda s: s[0] + s[1:].lower(), last_names))
    
    with open(txt_file, "w") as file:
        file.writelines(f"{get_employee_data(first_names,last_names)}\n" for _ in range(lines))

def main():
    if len(sys.argv) < 2:
        print("Usage: generate.py N, where N is number of lines of employee data to generate")
        return
    output_file(int(sys.argv[1]))

if __name__ == "__main__":
    main()





"""
Koren Rice | Full | 42484 | Male | 53
Amelita Rivers | Full | 68989 | Female | 26
Hyacinth Simon | Part | 18-11 | Female | 21
"""

