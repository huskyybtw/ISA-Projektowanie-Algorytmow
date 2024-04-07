def generateFile():
    with open("data200", "w") as file:
        for i in range(0, 200_000):
            file.write(str(i+1) + "\n")

def are_files_equal(file1, file2):
    with open(file1, 'rb') as f1, open(file2, 'rb') as f2:
        return f1.read() == f2.read()

def main():
    file1 = "data200"
    file2 = "data200_output"

    if are_files_equal(file1, file2):
        print("Files are equal.")
    else:
        print("Files are not equal.")

if __name__ == "__main__":
    main()