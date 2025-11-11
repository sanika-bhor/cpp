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
    int completion;
    int turnaround;
    int waiting;
    int start;
};

// Comparator to sort by arrival time
bool compareArrival(Process a, Process b)
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid; // if arrival is same, sort by process ID
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
    }

    // Sort by arrival time (and process ID for tie-breaking)
    sort(p.begin(), p.end(), compareArrival);

    int currentTime = 0;
    vector<int> readyQueue;

    cout << "\n--- FCFS Scheduling Simulation ---\n";

    for (int i = 0; i < n; i++)
    {
        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival; // CPU is idle until process arrives

        p[i].start = currentTime;
        readyQueue.push_back(p[i].pid);

        p[i].completion = currentTime + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        currentTime = p[i].completion;
    }

    // Display Ready Queue Order
    cout << "\nReady Queue Order (FCFS): ";
    for (auto pid : readyQueue)
    {
        cout << "P" << pid << " ";
    }
    cout << "\n";

    // Display Table
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

    // Gantt Chart
    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < n; i++)
    {
        cout << "|  P" << p[i].pid << "  ";
    }
    cout << "|\n";

    cout << p[0].start;
    for (int i = 0; i < n; i++)
    {
        cout << setw(7) << p[i].completion;
    }
    cout << "\n";

    return 0;
}