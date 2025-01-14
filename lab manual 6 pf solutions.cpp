//Generate a sequence where the next number is the sum of the previous two, similar to
//Fibonacci.However, if the position of number in the sequence is even, subtract it with the next
//number, otherwise add.The user provides the length of the series.
#include<iostream>
using namespace std;

int main() {
    // Declare variables
    int length;
    cout << "Enter the length of the series: ";
    cin >> length;

    // Initialize the first two numbers of the series
    int a = 0, b = 1;

    // Print the first two numbers
    cout << a << " " << b << " ";

    // Loop to generate the series
    for (int i = 3; i <= length; i++) {
        // Calculate the next number as the sum of the previous two
        int next = a + b;

        // If the position is even, subtract the next number, otherwise add
        if (i % 2 == 0) {
            next = next - b;
        }
        else {
            next = next + b;
        }

        // Print the next number
        cout << next << " ";

        // Update a and b for the next iteration
        a = b;
        b = next;
    }

    cout << endl;
    return 0;
}

//Take a positive integer n from the user.If n is even and less than 10, multiply it by 5. If n is
//even and greater than 10, divide it by 2. If n is odd, multiply it by 3 and add 1. Repeat the process
//until reaching 3 or the 40 iterations are completed and print the sequence.Use the below method
//for output.
#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int count = 0;
    cout << n << " ";

    while (n != 3 && count < 40) {
        if (n % 2 == 0) {
            if (n < 10) {
                n *= 5;
            }
            else {
                n /= 2;
            }
        }
        else {
            n = n * 3 + 1;
        }
        cout << n << " ";
        count++;
    }

    cout << endl;
    return 0;
}

//
//Take an integer n from the user.For each number from 1 to n, display its divisors in a row.
//If the current number has an odd number of divisors, print ODD next to it; otherwise, print
// EVEN; 
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
                cout << j << " ";
            }
        }
        if (count % 2 == 0) {
            cout << "EVEN";
        }
        else {
            cout << "ODD";
        }
        cout << endl;
    }
    return 0;
}


//Accept a number from the user.If the number is prime, multiply the digits together.If it Is
//even but not prime, reverse the digits.If it Is odd but not prime, calculate the sum of its digits.
//Display the result.

#include<iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    cin >> num;

    if (isPrime(num)) {
        int product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        cout << product;
    }
    else if (num % 2 == 0) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        cout << reversed;
    }
    else {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        cout << sum;
    }

    return 0;
}


//Given a 3x3 matrix, if the matrix is a magic square, check if the matrix formed by the sum of
//each of its 2x2 sub - matrices is also a magic square.To determine if a 3x3 matrix is a magic square,
//
//we need to check that the sum of the numbers in each row, each column, and both main diagonals
//are the same.A magic square has the property:
//Sum of each row or column = n(n ^ 2 + 1) / 2, where n is the size of the matrix(in this case 3).
//If the 3x3 matrix is a magic square, we can then extract its four 2x2 sub - matrices and form a new
//matrix by calculating the sum of each of these sub - matrices.Finally, we will check if this resulting
//matrix is also a magic square.

#include<iostream>
using namespace std;

bool isMagicSquare(int matrix[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += matrix[i][0]; // Sum of the first row
    }

    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != sum || colSum != sum) return false;
    }

    int diagonal1 = matrix[0][0] + matrix[1][1] + matrix[2][2];
    int diagonal2 = matrix[0][2] + matrix[1][1] + matrix[2][0];

    if (diagonal1 != sum || diagonal2 != sum) return false;

    return true;
}

bool isSubMatrixMagic(int subMatrix[2][2]) {
    int sum = subMatrix[0][0] + subMatrix[0][1];

    for (int i = 0; i < 2; i++) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < 2; j++) {
            rowSum += subMatrix[i][j];
            colSum += subMatrix[j][i];
        }
        if (rowSum != sum || colSum != sum) return false;
    }

    int diagonal1 = subMatrix[0][0] + subMatrix[1][1];
    int diagonal2 = subMatrix[0][1] + subMatrix[1][0];

    if (diagonal1 != sum || diagonal2 != sum) return false;

    return true;
}

int main() {
    int matrix[3][3];
    cout << "Enter a 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    if (!isMagicSquare(matrix)) {
        cout << "The 3x3 matrix is not a magic square." << endl;
        return 0;
    }

    int subMatrix[2][2];
    int sumMatrix[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            subMatrix[i][j] = matrix[i][j] + matrix[i + 1][j + 1];
            sumMatrix[i][j] = subMatrix[i][j];
        }
    }

    cout << "The sum of the 2x2 sub-matrices:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << sumMatrix[i][j] << " ";
        }
        cout << endl;
    }

    if (isSubMatrixMagic(sumMatrix)) {
        cout << "The sum of the 2x2 sub-matrices forms a magic square." << endl;
    }
    else {
        cout << "The sum of the 2x2 sub-matrices does not form a magic square." << endl;
    }

    return 0;
}


//Find all numbers up to a given number n which are equal to half the sum of their divisors,
//and display them.
#include<iostream>
using namespace std;

int sumOfDivisors(int num) {
    int sum = 1;  // 1 is always a divisor
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number n: ";
    cin >> n;

    cout << "Numbers which are equal to half the sum of their divisors:" << endl;
    for (int i = 1; i <= n; i++) {
        int sum = sumOfDivisors(i);
        if (i == sum / 2) {
            cout << i << endl;
        }
    }

    return 0;
}


//Check if a given number is a palindrome.If it is, check if the number formed by its digits in
//ascending order is also a palindrome.
#include<iostream>
#include<algorithm>
using namespace std;

bool isPalindrome(int num) {
    int original = num, reversed = 0, digit;
    while (num > 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;

        // Convert number to string to sort digits
        string str = to_string(num);
        sort(str.begin(), str.end());

        // Convert sorted string back to number
        int sortedNum = stoi(str);

        if (isPalindrome(sortedNum)) {
            cout << "The number formed by its digits in ascending order, " << sortedNum << ", is also a palindrome." << endl;
        }
        else {
            cout << "The number formed by its digits in ascending order, " << sortedNum << ", is not a palindrome." << endl;
        }
    }
    else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}

