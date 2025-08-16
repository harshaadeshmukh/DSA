/*
 * In this Java code, I have created a simulation of parking slots for vehicles using counting semaphores.
 * Basically, it allows a limited number of cars to park simultaneously
 * and ensures that no more than the specified number of cars can park at the same time.
 * If a car takes too long to park, it will release the parking slot after a certain period.
 */

import java.util.concurrent.Semaphore;
public class DemoWithCountingSemaphores {

    static Semaphore parkingSlot = new Semaphore(2); // 2 parking slots available

    static class Car extends Thread 
    {
        private int id;
        public Car (int id)
        {
            this.id = id;
        }

        public void run()
        // run method is basically the entry point for the thread
        {
            try{
                System.out.println("Car "+ id +" is waiting for parking slot...");

                parkingSlot.acquire(); // acquire a parking slot

                System.out.println("Car "+ id +" is parked.");

                Thread.sleep(3500); // simulate parking time

                System.out.println("Car "+ id +" is leaving.");

                parkingSlot.release(); // release the parking slot

            }
            catch (InterruptedException e) {
               e.printStackTrace();
            }
        }        
    }

    public static void main(String[] ar)
    {
        Car [] c = new Car[6];

        for (int i = 0; i < 6; i++) {
            c[i] = new Car(i);
            c[i].start();
        }

        for(int i =0;i<6;i++)
        {
            try{
                c[i].join();
                Thread.sleep(1000); // wait for a second before starting the next car
                
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

/*
 * Output (will give you o/p randomly)
Car 0 is waiting for parking slot...
Car 4 is waiting for parking slot...
Car 0 is parked.
Car 3 is waiting for parking slot...
Car 5 is waiting for parking slot...
Car 2 is waiting for parking slot...
Car 1 is waiting for parking slot...
Car 4 is parked.
Car 0 is leaving.
Car 4 is leaving.
Car 3 is parked.
Car 5 is parked.
Car 5 is leaving.
Car 3 is leaving.
Car 2 is parked.
Car 1 is parked.
Car 1 is leaving.
Car 2 is leaving.
 */

/*
1️⃣ What is a Semaphore?
 * Semaphore is a synchronization tool used to control access to a shared resource by multiple threads.
 * It is basically a counter that tracks how many threads can access the resource at the same time.
 * Semaphores prevent race conditions and ensure safe concurrent access.
 * There are two main types:
 * Binary Semaphore (Mutex-like): Can have only 0 or 1. Used for mutual exclusion.
 * Counting Semaphore: Can have any integer value, used when multiple threads can access multiple instances of a resource.
 * Semaphores are a powerful tool for managing concurrency and ensuring that shared resources are accessed in a controlled manner.
 * They help prevent issues like deadlocks and resource contention by limiting the number of threads that can access a resource simultaneously.

2️⃣ Counting Semaphore

 * A counting semaphore keeps a count of available resources.
 * It allows a specific number of threads to access the resource concurrently.
 * Example: If a parking lot has 2 slots, a counting semaphore is initialized to 2.
 * Working:
   When a thread wants to use a resource, it calls acquire():
   If the count is > 0 → decreases the count and allows the thread to proceed.
   If the count = 0 → thread waits until a resource is released.
   When a thread finishes using the resource, it calls release(),
   which increments the count and may wake up waiting threads.


3️⃣ How Your Parking Lot Code Works
 * Initialization:
 * Semaphore parkingLot = new Semaphore(2);
 * Parking lot has 2 slots → semaphore count = 2.

 * When a car arrives:
   Prints "Car X is waiting for a slot...".
   Calls parkingLot.acquire() → tries to get a slot:
   If a slot is free → parks and count decreases.

   If all slots are full → waits until a slot is released.
   Stays parked for 2 seconds (Thread.sleep(2000)).
   Calls parkingLot.release() → frees the slot and increments count.
   
   Behavior when multiple cars arrive:
   Only 2 cars can park at the same time (because semaphore count = 2).
   
   The other cars wait until a slot becomes free.
   This ensures no more than 2 cars park simultaneously, preventing conflicts.
 */
