from pathlib import Path

def main():
    BASE_DIR = Path(__file__).resolve().parent.parent.parent
    txt_file = BASE_DIR / "employees.txt"

    
if __name__ == "__main__":
    main()