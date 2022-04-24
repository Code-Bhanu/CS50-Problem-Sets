from cs50 import get_string

# Declaration of variables
index = 0
cnt_letter = 0
cnt_sent = 0
cnt_word = 0

# Text input from the user
s = get_string("Text: ")
length = len(s)

# Count number of letters, words, sentences in the text
for i in range(length):
    if s[i].isalpha():
        cnt_letter += 1
    elif s[i] == '.' or s[i] == '?' or s[i] == '!':
        cnt_sent += 1
    elif s[i] == ' ':
        cnt_word += 1
    i += 1

if not cnt_word == 0:
    cnt_word += 1


# Average letters and sentences per 100 words
L = (cnt_letter / cnt_word) * 100
S = (cnt_sent / cnt_word) * 100

# Coleman-Liau formula
index = round((0.0588 * L) - (0.296 * S) - 15.8)

# print grades
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))