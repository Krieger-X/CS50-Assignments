from cs50 import get_string


def main():
    # get user input
    text = get_string("Text: ")
    # functions for counting letters, words, sentences in the texts
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    # implement Coleman-Liau formula
    l = letters / words * 100
    s = sentences / words * 100
    x = round(0.0588 * l - 0.296 * s - 15.8)

    # if index is less than 1 print before grade 1, if greater than 16 print 16+
    if x < 1:
        print(f"Before Grade 1")
    elif x > 16:
        print(f"Grade 16+")
    else:
        print(f"Grade {x}")


# function for counting letters
def count_letters(text):
    return len([x for x in text if x.isalpha()])


# function for counting words
def count_words(text):
    words = 1
    for i in range(len(text)):
        if text[i] == " ":
            words += 1
    return words


# function for counting sentences
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] in [".", "!", "?"]:
            sentences += 1
    return sentences


main()