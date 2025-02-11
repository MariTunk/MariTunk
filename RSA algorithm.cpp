#include <iostream>
#include <cassert>

using namespace std;

// Function for the Euclidean Algorithm
int EuclidAlgGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Extended Euclidean Algorithm
int ExtendedEuclidAlgGCD(int a, int b, int &s, int &t)
{
    if (b == 0)
    {
        s = 1;
        t = 0;
        return a;
    }
    // coefficients for recursion
    int s1, t1;
    int gcd = ExtendedEuclidAlgGCD(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;
    return gcd;
}

// Modular arithmetic function
int mod(int a, int n)
{
    int r = a % n;
    return r < 0 ? r + n : r;
}

// Function to find a number relatively prime to `n`
int RelativelyPrime(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (EuclidAlgGCD(n, i) == 1)
        {
            return i;
        }
    }
    return -1; // Should not happen for n > 2
}

// Function to find modular inverse
int inverse(int a, int n)
{
    int s, t;
    int gcd = ExtendedEuclidAlgGCD(n, a, s, t);
    if (gcd == 1)
    {
        return mod(t, n);
    }
    else
    {
        cout << "a and n are not relatively prime!\n";
        return -1;
    }
}

// Encode function
int Encode(int M, int e, int PQ)
{
    long long result = 1;
    long long base = M;
    while (e > 0)
    {
        if (e % 2 == 1)
        {
            // If e is odd
            result = (result * base) % PQ;
        }
    }
        base = (base * base) % PQ; // Square the base
        e /= 2;
 }
    return static_cast<int>(result);


// Decode function
int Decode(int C, int d, int PQ)
{
    long long result = 1;
    long long base = C;
    while (d > 0)
    {
        if (d % 2 == 1)
        {
            // If d is odd
            result = (result * base) % PQ;
        }
        base = (base * base) % PQ; // Square the base
        d /= 2;
    }
    return static_cast<int>(result);
3}



int main()
{
    // step 1: Test the  Euclidean Algorithm
    cout << "GCD of 48 and 18: " << EuclidAlgGCD(48, 18) << endl;

    // step 2: test the Euclidean Algorithm xtention 
    int s, t;
    int gcd = ExtendedEuclidAlgGCD(48, 18, s, t);
    cout << "GCD of 48 and 18 (Extended): " << gcd << ", s = " << s << ", t = " << t << endl;

    // step 3: test the mods
    cout << "-7 mod 3 = " << mod(-7, 3) << endl;

    // step 4: test relativity function
    int relPrime = RelativelyPrime(120);
    cout << "Relatively prime to 120: " << relPrime << endl;

    // step 5: test the invesrse mod 
    int inv = inverse(7, 40);
    if (inv != -1)
    {
        cout << "Inverse of 7 mod 40: " << inv << endl;
    }

    // RSA Implementation
    const int P = 23;
    const int Q = 17;
    const int PQ = P * Q;
    const int phi = (P - 1) * (Q - 1);

    int e = RelativelyPrime(phi);
    cout << "Public key (e): " << e << endl;

    int d = inverse(e, phi);
    cout << "Private key (d): " << d << endl;

    // Testing RSA
    int M;
    cout << "Enter an integer smaller than " << PQ << ": ";
    cin >> M;

    int C = Encode(M, e, PQ);
    cout << "Encoded message: " << C << endl;

    int M1 = Decode(C, d, PQ);
    cout << "Decoded message: " << M1 << endl;

    assert(M == M1);
    cout << "RSA works correctly!\n";

    return 0;
}
