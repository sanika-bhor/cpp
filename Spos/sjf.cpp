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
    int remaining;
    int completion;
    int turnaround;
    int waiting;
    bool completed;
};

// Comparator to sort by arrival time
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
        p[i].remaining = p[i].burst;
        p[i].completed = false;
    }

    // Sort by arrival time initially
    sort(p.begin(), p.end(), compareArrival);

    int completed = 0;
    int currentTime = 0;
    vector<int> gantt; // To store Gantt chart order

    cout << "\n--- SJF (Preemptive) Scheduling Simulation ---\n";

    while (completed != n)
    {
        int idx = -1;
        int minRemaining = 1e9;

        // Find process with shortest remaining time at current time
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival <= currentTime && !p[i].completed && p[i].remaining < minRemaining)
            {
                minRemaining = p[i].remaining;
                idx = i;
            }
        }

        if (idx != -1)
        {
            gantt.push_back(p[idx].pid);
            p[idx].remaining--;
            currentTime++;

            // If process finished
            if (p[idx].remaining == 0)
            {
                p[idx].completed = true;
                p[idx].completion = currentTime;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                completed++;
            }
        }
        else
        {
            // No process is ready to execute (CPU idle)
            currentTime++;
        }
    }

    // Display Gantt chart
    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < gantt.size(); i++)
    {
        if (i == 0 || gantt[i] != gantt[i - 1])
            cout << "|  P" << gantt[i] << "  ";
    }
    cout << "|\n0";
    int time = 0;
    for (int i = 0; i < gantt.size(); i++)
    {
        time++;
        if (i == gantt.size() - 1 || gantt[i] != gantt[i + 1])
            cout << setw(6) << time;
    }
    cout << "\n";

    // Display Result Table
    cout << "\n+---------+--------------+------------+----------------+----------------+--------------+\n";
    cout << "| PID     | Arrival Time | Burst Time | Completion Time| Turnaround Time| Waiting Time |\n";
    cout << "+---------+--------------+------------+----------------+----------------+--------------+\n";

    float avgTAT = 0, avgWT = 0;
    for (auto &proc : p)
    {
        cout << "| P" << setw(3) << proc.pid
             << "    | " << setw(12) << proc.arrival
             << " | " << setw(10) << proc.burst
             << " | " << setw(14) << proc.completion
             << " | " << setw(14) << proc.turnaround
             << " | " << setw(12) << proc.waiting << " |\n";

        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }
    cout << "+---------+--------------+------------+----------------+----------------+--------------+\n";

    cout << "\nAverage Turnaround Time: " << (avgTAT / n);
    cout << "\nAverage Waiting Time: " << (avgWT / n) << "\n";

    return 0;
}