#include <iostream>

/** intNumPathsFromHome:
 *  Calculates number of possible paths from given starting position to (0,0)
 *
 * @param street - integer, starting position y value
 * @param avenue - integer, starting position x value
 * @return       - integer, number of paths
 */
int numPathsFromHome(int street, int avenue);

/** hasSubsequence:
 * Determines if c-string S is a subsequent of c-string T
 *
 * @param T - c-string
 * @param S - c-string
 * @param i - integer, index for T
 * @param j - integer, index for S
 * @return  - boolean, true if S is Subsequence of T, false if it's not
 */
bool hasSubsequence(const char T[], const char S[]);
bool hasSubsequence(const char T[], const char S[], int i, int j);

// Main Function
int main()
{
    std::cout << std::endl;

    // Calling numPathsFromHome
    int street = 1,
        avenue = 2;
    std::cout << "<< numPathsFromHome >>" << std::endl;
    std::cout << "Street: " << street << std::endl;
    std::cout << "Avenue: " << avenue << std::endl;
    std::cout << "Paths: " << numPathsFromHome(street, avenue) << std::endl;
    std::cout << std::endl;

    // Calling hasSubsequence
    const char string1[] = "programming",
               string2[] = "pin",
               string3[] = "least",
               string4[] = "steal",
               string5[] = "p",
               string6[] = "team",
               string7[] = "springtime",
               string8[] = "";
    std::cout << "<< hasSubsequence >>" << std::endl;
    std::cout << "'" << string2 << "' is subsequence of '" << string1 << "': " << hasSubsequence(string1, string2) << std::endl;
    std::cout << "'" << string4 << "' is subsequence of '" << string3 << "': " << hasSubsequence(string3, string4) << std::endl;
    std::cout << "'" << string5 << "' is subsequence of '" << string6 << "': " << hasSubsequence(string6, string5) << std::endl;
    std::cout << "'" << string8 << "' is subsequence of '" << string7 << "': " << hasSubsequence(string7, string8) << std::endl;
    std::cout << "'" << string7 << "' is subsequence of '" << string8 << "': " << hasSubsequence(string8, string7) << std::endl;
    std::cout << "'" << string8 << "' is subsequence of '" << string8 << "': " << hasSubsequence(string8, string8) << std::endl;
    std::cout << std::endl;
}

// Function definitions
int numPathsFromHome(int street, int avenue)
{
    if (street == 0 && avenue == 0)
        return 1;

    int paths = 0;
    if (street > 0)
        paths += numPathsFromHome(street - 1, avenue);

    if (avenue > 0)
        paths += numPathsFromHome(street, avenue - 1);

    return paths;
}

bool hasSubsequence(const char T[], const char S[])
{
    return hasSubsequence(T, S, 0, 0);
}
bool hasSubsequence(const char T[], const char S[], int i, int j)
{
    if (T[i] == '\0' && S[i] != '\0')
        return false;

    if (S[j] == '\0')
        return true;

    if (T[i] == S[j])
        return hasSubsequence(T, S, i + 1, j + 1);

    return hasSubsequence(T, S, i + 1, j);
}