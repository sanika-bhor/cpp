#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <chrono>

using namespace std;

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

// Mutex for critical section
mutex mtx;

// Semaphores
sem_t empty1; // Counts empty slots
sem_t full;  // Counts full slots

void producer()
{
    for (int i = 1; i <= 10; i++)
    {
        sem_wait(&empty1); // Wait if buffer is full
        mtx.lock();       // Enter critical section

        buffer[in] = i;
        cout << "Producer produced: " << i << " at index " << in << endl;
        in = (in + 1) % BUFFER_SIZE;

        mtx.unlock();    // Exit critical section
        sem_post(&full); // Increase count of full slots

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void consumer()
{
    for (int i = 1; i <= 10; i++)
    {
        sem_wait(&full); // Wait if buffer is empty
        mtx.lock();      // Enter critical section

        int item = buffer[out];
        cout << "Consumer consumed: " << item << " from index " << out << endl;
        out = (out + 1) % BUFFER_SIZE;

        mtx.unlock();     // Exit critical section
        sem_post(&empty1); // Increase count of empty slots

        this_thread::sleep_for(chrono::milliseconds(800));
    }
}

int main()
{
    // Initialize semaphores
    sem_init(&empty1, 0, BUFFER_SIZE); // Initially buffer has BUFFER_SIZE empty slots
    sem_init(&full, 0, 0);            // Initially buffer has 0 full slots

    // Create threads
    thread prod(producer);
    thread cons(consumer);

    // Wait for threads to finish
    prod.join();
    cons.join();

    // Destroy semaphores
    sem_destroy(&empty1);
    sem_destroy(&full);

    return 0;
}