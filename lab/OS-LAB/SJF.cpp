#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cout << "Enter Number of Processes: ";
    cin >> n;

    int p[20], at[20], bt[20], ct[20], wt[20], tat[20];
    bool completed[20];

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time : ";
        cin >> at[i];

        cout << "Burst Time   : ";
        cin >> bt[i];

        completed[i] = false;
    }

    int currentTime = 0;
    int completedCount = 0;

    int ganttP[20];
    int ganttT[21];
    int k = 0;

    while(completedCount < n)
    {
        int idx = -1;
        int minBT = 9999;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= currentTime && completed[i] == false)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    idx = i;
                }
                else if(bt[i] == minBT)
                {
                    if(at[i] < at[idx])
                        idx = i;
                }
            }
        }

        if(idx == -1)
        {
            currentTime++;
        }
        else
        {
            ganttP[k] = p[idx];
            ganttT[k] = currentTime;
            k++;

            currentTime += bt[idx];

            ct[idx] = currentTime;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed[idx] = true;
            completedCount++;
        }
    }

    ganttT[k] = currentTime;

    cout << "\n=========== GANTT CHART ===========\n";

    for(int i = 0; i < k; i++)
        cout << "-------";
    cout << "-\n";

    for(int i = 0; i < k; i++)
        cout << "| P" << ganttP[i] << " ";

    cout << "|\n";

    for(int i = 0; i < k; i++)
        cout << "-------";
    cout << "-\n";

    for(int i = 0; i <= k; i++)
        cout << ganttT[i] << "\t";

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