# TODO
import cs50

def main():
    texts = cs50.get_string("text:")
    lettercount = count_letter(texts)
    wordcount = count_word(texts)
    sentencecount = count_sentence(texts)

    L = float(100 * lettercount / wordcount)
    S = float(100 * sentencecount / wordcount)
    index = round (0.0588 * L - 0.296 * S - 15.800)

    print_grade(index)

def count_letter(text):
    letters = 0
    for z in range(len(text)):
        letterz = ord(text[z])
        if (letterz > 96 and letterz < 122) or (letterz > 64 and letterz < 91):
            letters = letters + 1
    return letters

def count_word(text):
    words = 1
    for x in range(len(text)):
        if (text[x] == " "):
            words = words + 1
    return words

def count_sentence(text):
    sentences = 0
    for y in range (len(text)):
        if (text[y] == "." or text[y] == "!" or text[y] == "?"):
            sentences = sentences + 1
    return sentences

def print_grade(index):
    if index >= 1 and index <= 16:
        print("Grade", index)
    elif index < 1:
        print("Before Grade 1\n")
    else:
    	print("Grade 16+\n")


if __name__ == "__main__":
    main()