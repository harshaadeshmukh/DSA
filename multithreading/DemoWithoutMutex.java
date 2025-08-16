/* 
Here in this Java program, I created a simple ATM simulation 
where two threads try to withdraw money from the same account balance. 
Since both threads are sharing the same data (the balance) and 
modifying it at the same time without synchronization, a race condition can occur. 
This may lead to inconsistent results, such as both withdrawals succeeding even 
when the balance is insufficient, which could result in a negative balance or wrong final output.
*/

class DemoWithoutMutex
{

    private int balance = 100;

    @SuppressWarnings("deprecation")
    // meaning of deprecation is that Don’t show warnings if I use deprecated methods/classes inside this code

    public void withdrawMoney(int amount) // without applying mutex or synchronization
    {
        if(balance >= amount)
        {
            System.out.println(Thread.currentThread().getId()+" Processing Withdrawal...");

            try
            {
               Thread.sleep(1000);
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
        DemoWithoutMutex demo = new DemoWithoutMutex();

        Thread t1 = new Thread(()-> demo.withdrawMoney(50));
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

Case 1 → Output = Final Balance 20
21 Processing Withdrawal...
22 Processing Withdrawal...
21 Withdrawal Completed. New Balance: 20
22 Withdrawal Completed. New Balance: 20
Balance: 20

Here, both threads read balance one after another correctly:
Thread 21 starts → sees 100 → deducts 80 → balance = 20.
Thread 22 starts after update → sees 20 → still passes check (20 >= 80? ❌ No).

Wait, so why "Withdrawal Completed. New Balance: 20"?
👉 Because both passed the check at the start (when balance was still 100), 
then they both executed subtraction, but the scheduling overlapped in a way 
that balance got overwritten back to 20 (thread timing weirdness).



🔎 Case 2 → Output = Final Balance -60
21 Processing Withdrawal...
22 Processing Withdrawal...
21 Withdrawal Completed. New Balance: 20
22 Withdrawal Completed. New Balance: -60
Balance: -60
Here, both passed the if-check at the same time (when balance was still 100).
Thread 21 subtracts → balance = 20.
Thread 22 subtracts again → balance = -60 ❌
This is the classic race condition → two withdrawals succeed even though money was insufficient.



🔎 When could else print?
It can print, but only if:
One thread completely finishes (balance becomes 20 or -60),
And the second thread starts fresh after that, checking if (balance >= 80) on the updated value.
But in practice (since you added Thread.sleep(1000) inside), 
both threads overlap and "see" balance as 100 at the same time → so else is skipped almost always.



Case: Without Mutex (balance = 100, both withdraw 50)
Expected behavior:
Thread 1 checks → balance = 100 ≥ 50 ✅
Thread 2 checks → balance = 100 ≥ 50 ✅
Each subtracts 50 → Final balance = 0 ✅
Looks fine if things happen sequentially.


What can actually happen (Race Condition ⚠️):
Critical section:
if (balance >= amount) {    balance -= amount;      }

Possible sequence:
Thread 1 checks balance (100 ≥ 50) ✅ → goes to sleep.
Thread 2 checks balance (100 ≥ 50) ✅ → also goes to sleep.
Both wake up and subtract:
Thread 1: 100 – 50 = 50
Thread 2: 100 – 50 = 50
Final balance = 50, not 0 ❌
This is called the lost update problem: 
both threads read the same old value (100), 
and overwrite each other’s changes.
 */

 