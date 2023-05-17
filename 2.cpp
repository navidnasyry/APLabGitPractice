#include <iostream>
#include <string>

using namespace std;

// count all the specific char in the whole array of strings
int countAllSpecificChars(string sArr[], int arrLength, char specificChar) {
    int count = 0;//the count variable must be initialized to 0
    for (int i = 0; i < arrLength; ++i)//I changed the <= to < as because i range shuld be this
        for (int j = 0; j < sArr[i].size(); ++j)//I changed the <= to < as it must be(j refers to index not number of element)
            // if the jth char of the string is the specific char
            if (sArr[i][j] == specificChar)//i changed the assainment operator to equality operator
                count++;
    return count;
}

int main() {
    string sArr[4] = {
            "I am",
            "in",
            "ap",
            "class"
    };
    char findIt;
    cin >> findIt;
    cout << countAllSpecificChars(sArr, 4, findIt);
}