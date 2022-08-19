#include <iostream>
using namespace std;

struct process
{
    int id, at, bt, ct, tat, wt;
};
int main()
{
    int n;
    float atat = 0, awt = 0;
    cout << "Enter Total Number Of Process  ";
    cin >> n; // Total n number of processes
    process p[n];
    cout << "Enter the Arrival Time and Burst Time" << endl;
    for (int i = 0; i < n; i++)
    { // Storing arrival time and burst time data of processes
        cout << "Arrival Time of Process " << i + 1 << "\t";
        cin >> p[i].at;
        cout << "Burst Time of Process " << i + 1 << "\t\t";
        cin >> p[i].bt;
        p[i].id = i + 1;
    }
    /* Now first of all we are going to sort all processes according to their arrival time */
    for (int i = 0; i < n - 1; i++) // applying Bubble Sort
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                swap(p[j], p[j + 1]); // Swap() function to swap adjacent elements
            }
        }
    }
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    awt = p[0].wt;
    atat = p[0].tat;
    for (int i = 1; i < n; i++)
    {
        int var, key, least;
        /* "var" variable is used to check the processes that have arrived during the execution of the current process.
           "least" variable will decide which variable will compare the least burst time of the processes that have arrived.
           "key" variable will have the index of the process that is going to be under execution according to the SJF algorithm.
        */

        least = p[i].bt;
        var = p[i - 1].ct;
        for (int j = i; j < n; j++)
        {
            if (var >= p[j].at && least >= p[j].bt)
            {
                least = p[j].bt;
                key = j;
            }
        }
        p[key].ct = p[i - 1].ct + p[key].bt;
        p[key].tat = p[key].ct - p[key].at;
        p[key].wt = p[key].tat - p[key].bt;

        atat += p[key].tat;
        awt += p[key].wt;

        swap(p[key], p[i]);
    }
    for (int i = 0; i < n - 1; i++) // applying Bubble Sort
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].id > p[j + 1].id)
            {
                swap(p[j], p[j + 1]); // Swap() function to swap adjacent elements
            }
        }
    }

    cout << endl
         << endl;
    cout.width(42);
    cout << "ACCORDING TO SJF ALGORITHM" << endl;

    cout << endl
         << endl;

    cout.width(5);
    cout << "P.Id";
    cout.width(5);
    cout << "AT";
    cout.width(5);
    cout << "BT";
    cout.width(5);
    cout << "CT";
    cout.width(5);
    cout << "TAT";
    cout.width(5);
    cout << "WT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout.width(5);
        cout << p[i].id;
        cout.width(5);
        cout << p[i].at;
        cout.width(5);
        cout << p[i].bt;
        cout.width(5);
        cout << p[i].ct;
        cout.width(5);
        cout << p[i].tat;
        cout.width(5);
        cout << p[i].wt << endl;
    }
    /* The output obtained will be in terms of sorted array of processes */
    cout << "The average Turn Around Time is : " << atat / n << endl;
    cout << "The average Waiting Time is     : " << awt / n << endl;

    return 0;
}