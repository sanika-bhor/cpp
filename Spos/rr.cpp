#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main()
{
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Process ID: ";
        cin >> p[i].pid;
        cout << "Enter Arrival Time: ";
        cin >> p[i].arrival;
        cout << "Enter Burst Time: ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
    }

    cout << "\nEnter Time Quantum: ";
    cin >> quantum;

    int currentTime = 0, completed = 0;
    queue<int> q; // ready queue
    vector<int> gantt;

    vector<bool> inQueue(n, false);

    cout << "\n--- Round Robin Scheduling Simulation ---\n";

    // Push first process that arrives at time 0
    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival <= currentTime && !inQueue[i])
        {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        // Add to Gantt chart
        gantt.push_back(p[idx].pid);

        int execTime = min(quantum, p[idx].remaining);
        p[idx].remaining -= execTime;
        currentTime += execTime;

        // Check newly arrived processes
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival <= currentTime && !inQueue[i] && p[i].remaining > 0)
            {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p[idx].remaining == 0)
        {
            p[idx].completion = currentTime;
            completed++;
        }
        else
        {
            // If process not finished, push it again
            q.push(idx);
        }

        // If queue empty but some process is still not arrived
        if (q.empty() && completed < n)
        {
            for (int i = 0; i < n; i++)
            {
                if (p[i].remaining > 0)
                {
                    currentTime = max(currentTime, p[i].arrival);
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }
    }

    // Calculate turnaround and waiting times
    float avgTAT = 0, avgWT = 0;
    for (auto &proc : p)
    {
        proc.turnaround = proc.completion - proc.arrival;
        proc.waiting = proc.turnaround - proc.burst;
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    // Display Gantt Chart
    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < gantt.size(); i++)
    {
        if (i == 0 || gantt[i] != gantt[i - 1])
            cout << "|  P" << gantt[i] << "  ";
    }
    cout << "|\n0";

    int t = 0;
    for (int i = 0; i < gantt.size(); i++)
    {
        t += quantum;
        cout << setw(6) << (t);
    }
    cout << "\n";

    // Display Table
    cout << "\n+---------+--------------+------------+----------------+----------------+--------------+\n";
    cout << "| PID     | Arrival Time | Burst Time | Completion Time| Turnaround Time| Waiting Time |\n";
    cout << "+---------+--------------+------------+----------------+----------------+--------------+\n";

    for (auto &proc : p)
    {
        cout << "| P" << setw(3) << proc.pid
             << "    | " << setw(12) << proc.arrival
             << " | " << setw(10) << proc.burst
             << " | " << setw(14) << proc.completion
             << " | " << setw(14) << proc.turnaround
             << " | " << setw(12) << proc.waiting << " |\n";
    }

    cout << "+---------+--------------+------------+----------------+----------------+--------------+\n";

    cout << "\nAverage Turnaround Time: " << (avgTAT / n);
    cout << "\nAverage Waiting Time: " << (avgWT / n) << "\n";

    return 0;
}