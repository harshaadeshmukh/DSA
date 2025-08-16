/*
 * This Java program simulates multiple customers trying to use a single ATM.
 * A binary semaphore ensures that only one customer can use the ATM at a time.
 */

import java.util.concurrent.Semaphore;
public class DemoWithBinarySemaphores {
 
    static Semaphore atm = new Semaphore(1);

    static class Customer extends Thread{
        private int id;

        public Customer(int id)
        {
            this.id = id;
        }

        public void run()
        {
            try
            {
                System.out.println("Customer " + id + " is waiting to use ATM...");

                atm.acquire(); // Wait if ATM is busy
                System.out.println("Customer " + id + " is using the ATM.");
                
                Thread.sleep(2000); // simulate ATM usage
                System.out.println("Customer " + id + " has finished using the ATM.");

                atm.release(); // Free the ATM   

            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }          
        }
    }
    public static void main(String[] args) {
        Customer[] customers = new Customer[4];

        // 4 customers trying to use 1 ATM
        for (int i = 0; i < 4; i++) {
            customers[i] = new Customer(i + 1);
            customers[i].start();
        }

        // Wait for all customers to finish
        for (int i = 0; i < 4; i++) {
            try {
                Thread.sleep(1000);
                customers[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

/*
 * Output
Customer 4 is waiting to use ATM...
Customer 1 is waiting to use ATM...
Customer 2 is waiting to use ATM...
Customer 3 is waiting to use ATM...
Customer 4 is using the ATM.
Customer 4 has finished using the ATM.
Customer 1 is using the ATM.
Customer 1 has finished using the ATM.
Customer 2 is using the ATM.
Customer 2 has finished using the ATM.
Customer 3 is using the ATM.
Customer 3 has finished using the ATM.
 * 
 */

/*
1️⃣ What is a Binary Semaphore?
 * - A binary semaphore has only 2 states: 1 (available) or 0 (unavailable).
 * - It works like a mutex: only one thread can access the shared resource at a time.
 * - Key operations:
 *      - acquire(): if semaphore = 1 → decreases to 0 and allows thread to proceed;
 *                   if semaphore = 0 → thread waits until it becomes 1.
 *      - release(): sets semaphore back to 1 and wakes up a waiting thread.
 * - Use case: single shared resource like ATM, printer, or critical section.
 *


2️⃣ How the ATM Code Works
 * - Initialization:
 *      Semaphore atm = new Semaphore(1); // only 1 ATM available
 *
 * - Customer arrives:
 *      - Prints "Customer X is waiting to use ATM..."
 *      - Calls atm.acquire():
 *          - If ATM is free → acquires it and starts using.
 *          - If ATM is busy → waits automatically until ATM is released.
 *
 * - Customer uses ATM:
 *      - Simulated by Thread.sleep(2000) → customer occupies ATM for 2 seconds.
 *
 * - Customer leaves:
 *      - Prints "Customer X has finished using ATM."
 *      - Calls atm.release() → frees ATM for next waiting customer.

 3️⃣ Behavior and Key Points
 * - Only 1 customer can use the ATM at any given time.
 * - Other customers automatically wait until the ATM is free.
 * - Threads are scheduled concurrently; the order of usage may vary each run.
 * - Binary semaphore ensures **mutual exclusion** and prevents conflicts.
 * - This pattern is useful for any single shared resource scenario.
 */
