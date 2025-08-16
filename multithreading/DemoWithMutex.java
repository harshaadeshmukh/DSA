/*
 * In this Java program of an ATM simulator, I have implemented a simple withdrawal system
 * using threads and synchronization to handle concurrent access to the account balance.
 * When t1 tries to withdraw 80, it succeeds, but t2 fails when trying to withdraw 50.
 * So, the final balance is 20.
 * Basically, it does not cause any race conditions.
 */

class DemoWithMutex
{
    private int balance = 100;

    @SuppressWarnings("deprecation")
    // meaning of deprecation is that Don’t show warnings if I use deprecated methods/classes inside this code

    public synchronized void withdrawMoney(int amount) // applying mutex or synchronization
    {
        if(balance >= amount)
        {
            System.out.println(Thread.currentThread().getId()+" Processing Withdrawal...");

            try
            {
               Thread.sleep(5000);
            }
            catch(Exception e) // or InterruptedException
            {
                e.printStackTrace();
            }
                balance -= amount;

                System.out.println(Thread.currentThread().getId()+" Withdrawal Completed. New Balance: " + balance);
        }
        else{
            System.out.println(Thread.currentThread().getId()+" Insufficient Balance.");
        }
    }

    public int getBalance()
    {
        return balance;
    }


    public static void main(String[] ar)
    {
        DemoWithMutex demo = new DemoWithMutex();

        Thread t1 = new Thread(()-> demo.withdrawMoney(80));
        Thread t2 = new Thread(()-> demo.withdrawMoney(50));

        t1.start();
        t2.start();

        try {
            // wait for both threads to finish
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Balance: " + demo.getBalance());
    }
}

/*
 * 21 Processing Withdrawal...  
 * 21 Withdrawal Completed. New Balance: 20
 * 22 Insufficient Balance.
 * Balance: 20
 */

 /*-------------------------------------------------------------------------------------------------------------- */


/*
- start()
When you call t.start(), 
it tells the JVM to create a new thread and run the code inside its run() method (or Runnable/lambda).
Without start(), the code just runs in the main thread, not a new one.
👉 Example:
t1.start(); // new thread begins


- join()
When you call t.join(), it means "wait here until this thread finishes."
The main thread (or whichever thread calls join) pauses until t completes.
👉 Example:
t1.join(); // main thread waits for t1 to finish
t2.join(); // then waits for t2 to finish

⚡So in your program:
start() → actually begins the two child threads.
join() → makes the main thread wait for them, 
so that the final balance is printed only after both withdrawals are done.

 */

 /*
Case 1: With start() but no join
Main thread:  create t1, t2
Main thread:  start t1 → runs withdrawMoney(80)
Main thread:  start t2 → runs withdrawMoney(50)
Main thread:  (does not wait, directly prints balance)
Child t1:     Processing Withdrawal...
Child t2:     Processing Withdrawal...
... (they run in parallel)
Main thread:  Balance: 100   <-- printed too early ❌
Child t1:     Withdrawal Completed. New Balance: 20
Child t2:     Insufficient Balance.

👉 Problem: Balance printed before children finish.


Case 2: With start() + join
Main thread:  create t1, t2
Main thread:  start t1 → runs withdrawMoney(80)
Main thread:  start t2 → runs withdrawMoney(50)
Main thread:  t1.join() → wait for t1
Main thread:  t2.join() → wait for t2
Child t1:     Processing Withdrawal...
Child t1:     Withdrawal Completed. New Balance: 20
Child t2:     Insufficient Balance.
Main thread:  Balance: 20   ✅ (correct, after both done)

👉 Here, join() ensures main thread pauses until t1 and t2 are completely finished.

⚡So, summary:
start() → actually launches the thread.
join() → forces the calling thread (main) to wait until the child thread is done.

  */


  /*
 * About I/O or sleep()
 * If t1 does Thread.sleep(5000) → that thread (t1) goes into a TIMED_WAITING state for 5 seconds.
 * During this time, the CPU is free to run t2 or even continue the main thread
 * (unless you called join to make main wait).
 * After 5 seconds, the JVM scheduler moves t1 back to Runnable,
 * and it continues execution.
⚡So:
✅ Main is a thread.
✅ Child threads can block (sleep/I/O), and others can still run.
✅ If main doesn’t use join, it doesn’t care whether children are done—it just keeps running.
 */
