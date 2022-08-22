/*
    In SRTF, Every process is sorted on the basis of shortest burst time and 
    executed only for one unit time and after that it re-check for arrived processes
    having shotest burst time.

*/
#include <iostream>
#include <cstring>
using namespace std;
struct process
{
    int id,at,bt,ct,tat,wt;
};
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF PROCESSES\t";
    cin >> n;
    process p[n];
    float atat = 0, awt = 0;
    int remaining_bt[n];
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Arrival Time of Process" << i + 1 << endl;
        cin >> p[i].at;
        cout << "Enter Burst Time of Process" << i + 1 << endl;
        cin >> p[i].bt;
        p[i].id = i + 1;
        remaining_bt[i] = p[i].bt;
        temp += p[i].bt;
    }
    int time = 0, completed = 0;
    int is_completed[n];
    memset(is_completed, 0, sizeof(is_completed));
    while (completed != n)
    {
        int index = -1;
        int mn = temp;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && is_completed[i] == 0)
            {
                if (remaining_bt[i] < mn)
                {
                    mn = remaining_bt[i];
                    index = i;
                }
                if (remaining_bt[i] == mn && p[i].at < p[index].at)
                {
                    mn = remaining_bt[i];
                    index = i;
                }
            }
        }

        if (index != -1)
        {
            remaining_bt[index] -= 1;
            time++;

            if (remaining_bt[index] == 0)
            {
                p[index].ct = time;
                p[index].tat = p[index].ct - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;

                atat += p[index].tat;
                awt += p[index].wt;

                is_completed[index] = 1;
                completed++;
            }
        }
        else
        {
            time++;
        }
    }
    cout << endl
         << endl;
    cout.width(42);
    cout << "ACCORDING TO SRTF ALGORITHM" << endl;

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