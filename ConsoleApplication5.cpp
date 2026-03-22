#include <iostream>
using namespace std;

class Chislo
{
protected:
    long n;

public:
    Chislo(long size = 0)
    {
        n = size;
    }

    virtual ~Chislo()
    {
    }

    long GetSize() const
    {
        return n;
    }

    virtual long long factorial(long x)
    {
        if (x < 0)
            return -1;

        long long result = 1;
        for (long i = 1; i <= x; i++)
        {
            result *= i;
        }
        return result;
    }
};

class Matrix : public Chislo
{
public:
    long arr[100];

    Matrix(long size = 0) : Chislo(size)
    {
    }

    ~Matrix()
    {
    }

    void Input()
    {
        cout << "Enter " << n << " positive integers:" << endl;
        for (long i = 0; i < n; i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    void ShowFactorials(Chislo* p)
    {
        cout << endl;
        cout << "Table of values and factorials:" << endl;
        cout << "------------------------------" << endl;
        cout << "Number\tFactorial" << endl;
        cout << "------------------------------" << endl;

        for (long i = 0; i < n; i++)
        {
            cout << arr[i] << "\t" << p->factorial(arr[i]) << endl;
        }
    }
};

int main()
{
    long size;

    cout << "Enter array size (1..100): ";
    cin >> size;

    if (size <= 0 || size > 100)
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    Matrix m(size);
    m.Input();

    Chislo* p = &m;
    m.ShowFactorials(p);

    return 0;
}