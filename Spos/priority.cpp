#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int priority;
    int start;
    int completion;
    int turnaround;
    int waiting;
    bool completed;
};

// Sort by arrival time first
bool compareArrival(Process a, Process b)
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid;
    return a.arrival < b.arrival;
}

int main()
{
    int n;
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
        cout << "Enter Priority (Lower number = Higher priority): ";
        cin >> p[i].priority;
        p[i].completed = false;
    }

    sort(p.begin(), p.end(), compareArrival);

    int completed = 0;
    int currentTime = 0;
    vector<int> gantt; // to store execution order

    cout << "\n--- Priority Scheduling (Non-Preemptive) Simulation ---\n";

    while (completed != n)
    {
        int idx = -1;
        int highestPriority = 1e9;

        // Find process with highest priority (lowest number)
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival <= currentTime && !p[i].completed)
            {
                if (p[i].priority < highestPriority)
                {
                    highestPriority = p[i].priority;
                    idx = i;
                }
                else if (p[i].priority == highestPriority)
                {
                    // If same priority, choose earlier arrival
                    if (p[i].arrival < p[idx].arrival)
                        idx = i;
                }
            }
        }

        if (idx != -1)
        {
            p[idx].start = currentTime;
            p[idx].completion = currentTime + p[idx].burst;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].completed = true;
            currentTime = p[idx].completion;
            gantt.push_back(p[idx].pid);
            completed++;
        }
        else
        {
            currentTime++; // CPU idle time
        }
    }

    // Display Gantt chart
    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < gantt.size(); i++)
    {
        cout << "|  P" << gantt[i] << "  ";
    }
    cout << "|\n";

    int time = 0;
    cout << "0";
    for (int i = 0; i < gantt.size(); i++)
    {
        for (auto &proc : p)
        {
            if (proc.pid == gantt[i])
            {
                time = proc.completion;
                cout << setw(7) << time;
            }
        }
    }
    cout << "\n";

    // Display Table
    cout << "\n+---------+--------------+------------+----------+----------------+----------------+--------------+\n";
    cout << "| PID     | Arrival Time | Burst Time | Priority | Completion Time| Turnaround Time| Waiting Time |\n";
    cout << "+---------+--------------+------------+----------+----------------+----------------+--------------+\n";

    float avgTAT = 0, avgWT = 0;
    for (auto &proc : p)
    {
        cout << "| P" << setw(3) << proc.pid
             << "    | " << setw(12) << proc.arrival
             << " | " << setw(10) << proc.burst
             << " | " << setw(8) << proc.priority
             << " | " << setw(14) << proc.completion
             << " | " << setw(14) << proc.turnaround
             << " | " << setw(12) << proc.waiting << " |\n";

        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    cout << "+---------+--------------+------------+----------+----------------+----------------+--------------+\n";
    cout << "\nAverage Turnaround Time: " << (avgTAT / n);
    cout << "\nAverage Waiting Time: " << (avgWT / n) << "\n";

    return 0;
}