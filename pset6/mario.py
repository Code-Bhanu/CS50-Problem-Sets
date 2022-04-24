from cs50 import get_int

height = 0
# Get input from user
while height < 1 or height > 8:
    height = get_int("Height: ")

l = height
for i in range(height):
    k = l-1
    # print spaces
    while(k > 0):
        print(" ", end="")
        k -= 1
    # print hashes
    for j in range(i+1):
        print("#", end="")
    print()
    l -= 1