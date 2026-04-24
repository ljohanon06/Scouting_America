from math import floor
from pathlib import Path

def get_single_age(line):
    tokens = line.split(" | ")
    age_token = tokens[4]
    return int(age_token)

def main():
    BASE_DIR = Path(__file__).resolve().parent.parent.parent
    txt_file = BASE_DIR / "employees.txt"

    with open(txt_file) as file:
        lines = file.readlines()
    age_sum = 0
    for line in lines:
        age_sum += get_single_age(line)
    average_age = age_sum/len(lines)
    years = floor(average_age)
    months = floor((average_age-years)*12)
    print(f"The average age of the employees is {years} years and {months} months")


if __name__ == "__main__":
    main()