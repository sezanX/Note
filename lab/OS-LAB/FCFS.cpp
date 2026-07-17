#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cout << "Enter Number of Processes: ";
    cin >> n;

    int p[20], at[20], bt[20], ct[20], wt[20], tat[20];

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time : ";
        cin >> at[i];

        cout << "Burst Time   : ";
        cin >> bt[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    if(at[0] == 0)
        ct[0] = bt[0];
    else
        ct[0] = at[0] + bt[0];

    for(int i = 1; i < n; i++)
    {
        if(ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\n\n=========== GANTT CHART ===========\n";

    for(int i = 0; i < n; i++)
        cout << "-------";
    cout << "-\n";

    for(int i = 0; i < n; i++)
        cout << "| P" << p[i] << " ";

    cout << "|\n";

    for(int i = 0; i < n; i++)
        cout << "-------";
    cout << "-\n";

    cout << at[0];

    for(int i = 0; i < n; i++)
        cout << "\t" << ct[i];

    float avgWT = 0;
    float avgTAT = 0;

    cout << "\n\n";
    cout << left
         << setw(10) << "Process"
         << setw(8) << "AT"
         << setw(8) << "BT"
         << setw(8) << "CT"
         << setw(8) << "WT"
         << setw(8) << "TAT"
         << endl;

    for(int i = 0; i < n; i++)
    {
        cout << left
             << setw(10) << ("P" + to_string(p[i]))
             << setw(8) << at[i]
             << setw(8) << bt[i]
             << setw(8) << ct[i]
             << setw(8) << wt[i]
             << setw(8) << tat[i]
             << endl;

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n;

    return 0;
}