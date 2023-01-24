import csv
import sys


def main():
    import pdb; pdb.set_trace()

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        database = list(reader)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # Find the longest match of each STR in DNA sequence
    # Store results in a dictionary
    str_counts = {}
    for STR in database[0][1:]:
        str_counts[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    # Print name of matching profile
    for row in database[1:]:
        # make row to int
        row_copy = [int(i) for i in row[1:]]
        if str_counts == dict(zip(database[0][1:], row_copy)):
            # print the name of the person
            print(row[0])
            return

    # If no matching profiles, print "No match"
    print("No match")

    return



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()