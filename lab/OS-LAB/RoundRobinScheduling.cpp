#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cout << "Enter Number of Processes: ";
    cin >> n;

    int p[20], at[20], bt[20], rem[20];
    int ct[20] = {0}, wt[20], tat[20];
    bool visited[20] = {false};

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time : ";
        cin >> at[i];

        cout << "Burst Time   : ";
        cin >> bt[i];

        rem[i] = bt[i];
    }

    int tq;

    cout << "\nEnter Time Quantum: ";
    cin >> tq;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(rem[i], rem[j]);
                swap(p[i], p[j]);
            }
        }
    }

    int queue[100];
    int front = 0, rear = 0;

    int currentTime = at[0];
    queue[rear++] = 0;
    visited[0] = true;

    int completed = 0;

    int ganttP[100];
    int ganttT[101];
    int k = 0;

    while(completed < n)
    {
        if(front == rear)
        {
            currentTime++;

            for(int i = 0; i < n; i++)
            {
                if(!visited[i] && at[i] <= currentTime)
                {
                    queue[rear++] = i;
                    visited[i] = true;
                }
            }

            continue;
        }

        int i = queue[front++];

        ganttP[k] = p[i];
        ganttT[k] = currentTime;
        k++;

        if(rem[i] > tq)
        {
            currentTime += tq;
            rem[i] -= tq;
        }
        else
        {
            currentTime += rem[i];
            rem[i] = 0;
            ct[i] = currentTime;
            completed++;
        }

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && at[j] <= currentTime)
            {
                queue[rear++] = j;
                visited[j] = true;
            }
        }

        if(rem[i] > 0)
        {
            queue[rear++] = i;
        }
    }

    ganttT[k] = currentTime;

    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

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