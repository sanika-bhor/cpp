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
    int start;
    bool completed;
};

// Comparator to sort by arrival time
bool compareArrival(Process a, Process b)
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid;
    return a.arrival < b.arrival;
}

// ------------------------ FCFS ------------------------
void FCFS(vector<Process> p)
{
    int n = p.size();
    sort(p.begin(), p.end(), compareArrival);

    int currentTime = 0;
    vector<int> readyQueue;

    cout << "\n--- FCFS Scheduling Simulation ---\n";

    for (int i = 0; i < n; i++)
    {
        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival;

        p[i].start = currentTime;
        readyQueue.push_back(p[i].pid);

        p[i].completion = currentTime + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        currentTime = p[i].completion;
    }

    cout << "\nReady Queue Order (FCFS): ";
    for (auto pid : readyQueue)
        cout << "P" << pid << " ";
    cout << "\n";

    float avgTAT = 0, avgWT = 0;
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
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }
    cout << "+---------+--------------+------------+----------------+----------------+--------------+\n";

    cout << "\nAverage Turnaround Time: " << (avgTAT / n);
    cout << "\nAverage Waiting Time: " << (avgWT / n) << "\n";

    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < n; i++)
        cout << "|  P" << p[i].pid << "  ";
    cout << "|\n";

    cout << p[0].start;
    for (int i = 0; i < n; i++)
        cout << setw(7) << p[i].completion;
    cout << "\n";
}

// ------------------------ SJF (Preemptive) ------------------------
void SJF_Preemptive(vector<Process> p)
{
    int n = p.size();
    for (int i = 0; i < n; i++)
    {
        p[i].remaining = p[i].burst;
        p[i].completed = false;
    }

    sort(p.begin(), p.end(), compareArrival);

    int completed = 0, currentTime = 0;
    vector<int> gantt;

    cout << "\n--- SJF (Preemptive) Scheduling Simulation ---\n";

    while (completed != n)
    {
        int idx = -1, minRemaining = 1e9;

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
            currentTime++;
        }
    }

    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < gantt.size(); i++)
        if (i == 0 || gantt[i] != gantt[i - 1])
            cout << "|  P" << gantt[i] << "  ";
    cout << "|\n0";

    int time = 0;
    for (int i = 0; i < gantt.size(); i++)
    {
        time++;
        if (i == gantt.size() - 1 || gantt[i] != gantt[i + 1])
            cout << setw(6) << time;
    }
    cout << "\n";

    float avgTAT = 0, avgWT = 0;
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
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }
    cout << "+---------+--------------+------------+----------------+----------------+--------------+\n";

    cout << "\nAverage Turnaround Time: " << (avgTAT / n);
    cout << "\nAverage Waiting Time: " << (avgWT / n) << "\n";
}

// ------------------------ MAIN ------------------------
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

    int choice;
    do
    {
        cout << "\n\nChoose Scheduling Algorithm:\n";
        cout << "1. FCFS\n";
        cout << "2. SJF (Preemptive)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            FCFS(p);
            break;
        case 2:
            SJF_Preemptive(p);
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
