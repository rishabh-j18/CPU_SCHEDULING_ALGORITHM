#include <iostream>
#include <algorithm>
using namespace std;

struct process
{ /* Class to store attributes of different processes separately */
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
    /* Now we are goint to sort out all processes with respect to arrival time
     of the processes. This is because the criteria for selecting processes is
     based on the arrival time of the process.  */
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
    /*Now we have sorted processes. we only have to sum the arrival time of first
     sorted process with its burst time to find its completion time and then for
     rest of the processes we have to sum the burst time with the completion time
     of the previous sorted sorted process */
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].ct = p[i].at + p[i].bt;
        }
        else
        { /*If after complete execution of certain process next process not arrived
          then the idol time of CPU will be added in the completion time of the next
          arrived process */
            if (p[i].at <= p[i - 1].ct)
            {
                p[i].ct = p[i - 1].ct + p[i].bt;
            }
            else
            {
                int temp = p[i].at - p[i - 1].ct;
                // temp variable is used to determine the idol time of the CPU
                p[i].ct = p[i - 1].ct + p[i].bt + temp;
            }
        }
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        atat += p[i].tat;
        awt += p[i].wt;
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
    cout << "ACCORDING TO FCFS ALGORITHM" << endl;

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
