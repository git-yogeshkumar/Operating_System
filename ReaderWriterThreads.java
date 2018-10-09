package readerwriterthreads;
import java.util.concurrent.Semaphore;
class ReaderWriter implements Runnable {
    int rc;
    Semaphore S=new Semaphore(1);
    Semaphore wrt=new Semaphore(2);
    public void run() 
    {
        try
        {
        S.acquire();
        rc++;
        if(rc==1)
            wrt.acquire();
            S.release();
            System.out.println("reading started by"+Thread.currentThread().getName());
            Thread.sleep(100);
            System.out.println("Read finish by"+Thread.currentThread().getName());
            S.acquire();
            rc--;
            if(rc==0)
                wrt.release();
            S.release();
        }
        catch(Exception e)
        {
            System.out.println("exception caught");
        }
    }    
}
class Writer implements Runnable{
    int rc;
    Semaphore S=new Semaphore(1);
    Semaphore wrt=new Semaphore(2);
    public void run()
    {
        try{
            wrt.acquire();
            System.out.println("writing started by"+Thread.currentThread().getName());
            Thread.sleep(5000);
            System.out.println("write finish by"+Thread.currentThread().getName());
            wrt.release();
        }
        catch(Exception e)
        {
            System.out.println("Exception caught");  
        }
    }
}

public class ReaderWriterThreads {
    int rc=0;
    public static void main(String[] args) throws Exception{
        while(true)
        {
            ReaderWriter r=new ReaderWriter();
            Thread t1=new Thread(r);
            Thread t2=new Thread(r);
            Writer w=new Writer();
            Thread t3=new Thread(w);
            t1.setName("thread1");
            t1.start();
            t2.setName("thread2");
            t2.start();
            t3.setName("thread3");
            t3.start();
        }
    }
}
