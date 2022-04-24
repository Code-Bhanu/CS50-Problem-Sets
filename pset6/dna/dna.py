import csv
import sys

# Ensure correct usage
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py database-filename sequence-filename")

names = []
# Read csv file into names list of dictionaries
filename = sys.argv[1]
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        names.append(row)

# Read sequence file in to a string
filename1 = sys.argv[2]
f = open(sys.argv[2], "r")
s = f.read()
strlen = len(s)

# The function that calculates the maximum repeated STR


def maximum(STR):
    i = 0
    j = len(STR)
    max = 0
    for x in range(strlen):
        if s[i:j] == STR:
            temp = 0
            while s[i:j] == STR:
                temp += 1
                i += len(STR)
                j += len(STR)
                if(temp > max):
                    max = temp
        else:
            i += 1
            j += 1

    return max


# finding out the number of occurences
agatc = maximum("AGATC")
aatg = maximum("AATG")
tatc = maximum("TATC")
ttttttct = maximum("TTTTTTCT")
tctag = maximum("TCTAG")
gata = maximum("GATA")
gaaa = maximum("GAAA")
tctg = maximum("TCTG")


person = ""

# Checking in small.csv file
if sys.argv[1] == "databases/small.csv":
    i = 0
    for i in range(len(names)):
        if int(names[i]["AGATC"]) == agatc and int(names[i]["AATG"]) == aatg and int(names[i]["TATC"]) == tatc:
            person = names[i]["name"]

# Checking in large.csv file
if sys.argv[1] == "databases/large.csv":
    i = 0
    for i in range(len(names)):
        if int(names[i]["AGATC"]) == agatc and int(names[i]["AATG"]) == aatg and int(names[i]["TATC"]) == tatc and int(names[i]["TTTTTTCT"]) == ttttttct and int(names[i]["TCTAG"]) == tctag and int(names[i]["GATA"]) == gata and int(names[i]["GAAA"]) == gaaa and int(names[i]["TCTG"]) == tctg:
            person = names[i]["name"]

# Print the results
if person == "":
    print("No match")
else:
    print(person)