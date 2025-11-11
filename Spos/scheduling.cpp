#include <iostream>
#include <vector>
#include <queue>
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
    int priority;
    bool completed;
};

// Comparator for sorting by arrival time
bool compareArrival(Process a, Process b)
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid;
    return a.arrival < b.arrival;
}

// ------------------- FCFS -------------------
void FCFS(vector<Process> p)
{
    int n = p.size();
    sort(p.begin(), p.end(), compareArrival);
    int currentTime = 0;
    vector<int> readyQueue;

    cout << "\n--- FCFS Scheduling ---\n";

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

    cout << "\nReady Queue Order: ";
    for (auto pid : readyQueue)
        cout << "P" << pid << " ";
    cout << "\n";

    float avgTAT = 0, avgWT = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p)
    {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    cout << "\nAverage Turnaround Time = " << avgTAT / n;
    cout << "\nAverage Waiting Time = " << avgWT / n << "\n";

    cout << "\nGantt Chart:\n ";
    for (auto &proc : p)
        cout << "|  P" << proc.pid << "  ";
    cout << "|\n";
    cout << p[0].start;
    for (auto &proc : p)
        cout << setw(7) << proc.completion;
    cout << "\n";
}

// ------------------- SJF (Preemptive) -------------------
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

    cout << "\n--- SJF (Preemptive) Scheduling ---\n";

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
            currentTime++;
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
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p)
    {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    cout << "\nAverage Turnaround Time = " << avgTAT / n;
    cout << "\nAverage Waiting Time = " << avgWT / n << "\n";
}

// ------------------- Priority (Non-Preemptive) -------------------
void Priority_NonPreemptive(vector<Process> p)
{
    int n = p.size();
    sort(p.begin(), p.end(), compareArrival);
    int completed = 0, currentTime = 0;
    vector<int> gantt;

    cout << "\n--- Priority Scheduling (Non-Preemptive) ---\n";

    while (completed != n)
    {
        int idx = -1, highestPriority = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival <= currentTime && !p[i].completed)
            {
                if (p[i].priority < highestPriority)
                {
                    highestPriority = p[i].priority;
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
            gantt.push_back(p[idx].pid);
            currentTime = p[idx].completion;
            completed++;
        }
        else
            currentTime++;
    }

    cout << "\nGantt Chart:\n ";
    for (auto id : gantt)
        cout << "|  P" << id << "  ";
    cout << "|\n";

    float avgTAT = 0, avgWT = 0;
    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (auto &proc : p)
    {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t" << proc.priority
             << "\t" << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    cout << "\nAverage Turnaround Time = " << avgTAT / n;
    cout << "\nAverage Waiting Time = " << avgWT / n << "\n";
}

// ------------------- Round Robin -------------------
void RoundRobin(vector<Process> p)
{
    int n = p.size(), quantum;
    cout << "Enter Time Quantum: ";
    cin >> quantum;

    for (auto &proc : p)
    {
        proc.remaining = proc.burst;
        proc.completed = false;
    }

    int currentTime = 0, completed = 0;
    queue<int> q;
    vector<int> gantt;
    vector<bool> inQueue(n, false);

    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival <= currentTime && !inQueue[i])
        {
            q.push(i);
            inQueue[i] = true;
        }
    }

    cout << "\n--- Round Robin Scheduling ---\n";

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        gantt.push_back(p[idx].pid);
        int exec = min(quantum, p[idx].remaining);
        p[idx].remaining -= exec;
        currentTime += exec;

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
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            completed++;
        }
        else
        {
            q.push(idx);
        }

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

    cout << "\nGantt Chart:\n ";
    for (int i = 0; i < gantt.size(); i++)
        if (i == 0 || gantt[i] != gantt[i - 1])
            cout << "|  P" << gantt[i] << "  ";
    cout << "|\n";

    float avgTAT = 0, avgWT = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p)
    {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.completion << "\t" << proc.turnaround << "\t" << proc.waiting << "\n";
        avgTAT += proc.turnaround;
        avgWT += proc.waiting;
    }

    cout << "\nAverage Turnaround Time = " << avgTAT / n;
    cout << "\nAverage Waiting Time = " << avgWT / n << "\n";
}

// ------------------- MAIN -------------------
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
        cout << "Enter Priority: ";
        cin >> p[i].priority;
    }

    int choice;
    do
    {
        cout << "\n\nChoose Scheduling Algorithm:\n";
        cout << "1. FCFS\n";
        cout << "2. SJF (Preemptive)\n";
        cout << "3. Priority (Non-Preemptive)\n";
        cout << "4. Round Robin\n";
        cout << "5. Exit\n";
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
            Priority_NonPreemptive(p);
            break;
        case 4:
            RoundRobin(p);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
