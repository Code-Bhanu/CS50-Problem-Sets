from cs50 import get_float

# Take cash as input from the user
while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

# Convert dollars to cents
cents = round(dollars * 100)

# Check number of 25 cents required for the change
i = 0
remain = 0
if not cents == 0:
    while True:
        cents = cents - (remain * 25)
        remain = cents // 25
        i = remain + i
        if remain == 0:
            break


# Check number of 10 cents required for the change
j = 0
remain = 0
if not cents == 0:
    while True:
        cents = cents - (remain * 10)
        remain = cents // 10
        j = remain + j
        if remain == 0:
            break

# Check number of 5 cents required for the change
k = 0
remain = 0
if not cents == 0:
    while True:
        cents = cents - (remain * 5)
        remain = cents // 5
        k = remain + k
        if remain == 0:
            break

# Check number of 1 cents required for the change
l = 0
remain = 0
if not cents == 0:
    while True:
        cents = cents - (remain * 1)
        remain = cents // 1
        l = remain + l
        if remain == 0:
            break
print(int(i + j + k + l))