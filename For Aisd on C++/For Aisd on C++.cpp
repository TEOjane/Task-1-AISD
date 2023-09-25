#include <iostream>
#include <iomanip>
using namespace std;

double* addElement(int n, double* numbers, double newElement)
{
    double* newNumbers{ new double[n + 1] };

    for (int i = 0; i < n; i++)
    {
        newNumbers[i] = numbers[i];
    }
    newNumbers[n] = newElement;

    return newNumbers;
}

double* deleteLastElement(int n, double* numbers)
{
    double* newNumbers{ new double[n - 1] };

    for (int i = 0; i < n - 1; i++)
    {
        newNumbers[i] = numbers[i];
    }

    return newNumbers;
}

double* addTwoElements(int n, double* numbers)
{
    double* newNumbers{ new double[n + 2] };
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        newNumbers[i] = numbers[i];
        sum += numbers[i];
    }

    newNumbers[n] = sum;
    newNumbers[n + 1] = sum / n;

    return newNumbers;
}


double* multThrid(int n, double* numbers)
{
    int first = 0, last = 0;

    for (int j = 0; j < n; j++)
    {
        if (numbers[0] < 0)
            first = 0;
        else if (numbers[j] < 0 && first == 0)
            first = j;

        if (numbers[j] < 0)
            last = j;
    }

    double temp = (numbers[first] + numbers[last]) * 2;

    for (int z = 2; z < n; z += 3)
    {
        numbers[z] *= temp;
    }

    return numbers;
}

void printArray(int n, double* numbers)
{
    for (int i = 0; i < n; i++)
    {
        cout << setprecision(3);
        cout << fixed << numbers[i] << " ";
       
    }

    cout << endl;
}

int main()
{
    int n, opr;
    cin >> n;

    double* numbers{ new double[n] };

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << n << endl;
    printArray(n, numbers);

    numbers = addTwoElements(n, numbers);
    n += 2;
    printArray(n, numbers);

    numbers = multThrid(n, numbers);
    printArray(n, numbers);

    cin >> opr;

    while (opr != 0)
    {
        if (opr == 1)
        {
            double newElement;
            cin >> newElement;

            numbers = addElement(n, numbers, newElement);
            n++;

            cout << "+: " << n << endl;
            printArray(n, numbers);
        }
        else
        {
            numbers = deleteLastElement(n, numbers);
            n--;
            cout << "-: " << n << endl;
            printArray(n, numbers);
        }

        numbers = addTwoElements(n, numbers);
        n += 2;
        printArray(n, numbers);

        numbers = multThrid(n, numbers);
        printArray(n, numbers);

        cin >> opr;
    }

}